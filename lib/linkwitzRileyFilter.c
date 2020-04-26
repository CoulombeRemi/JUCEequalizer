#include <stdlib.h>
#include <math.h>
#include "linkwitzRileyFilter.h"

#ifndef M_PI
#define M_PI (3.14159265358979323846264338327950288)
#endif
#include "compress.h"

static void filter_compute_coeffs(struct filter *data, float freq) {

	if (freq > data->nyquist) {
		data->freq = data->nyquist;
	}
	else if (freq < 10.0f) {
		data->freq = 10.0f;
	}
	else {
		data->freq = freq;
	}
	
	data->fpi = M_PI * data->freq;
	data->wc = data->fpi * 2;
	data->wc2 = data->wc * data->wc;
	data->wc22 = data->wc2 * 2;
	data->k = data->wc / tanf(data->fpi / data->sr);
	data->k2 = data->k * data->k;
	data->k22 = data->k2 * 2;
	data->wck = 2 * data->wc * data->k;
	data->tmpk = data->k2 + data->wc2 + data->wck;

	data->b1 = ((-1 * data->k22) + data->wc22) / data->tmpk;
	data->b2 = ((-1 * data->wck) + data->k2 + data->wc2) / data->tmpk;
	// lop
	data->a0_lp = data->wc2 / data->tmpk;
	data->a1_lp = data->wc22 / data->tmpk;
	data->a2_lp = data->a0_lp;
	// hip
	data->a0_hp = data->k2 / data->tmpk;
	data->a1_hp = (-1 * data->k22) / data->tmpk;
	data->a2_hp = data->a0_hp;
}

struct filter * filter_init(float freq, float sr, float thresh, float ratio, float att, float rel, float look) {
	struct filter *data = malloc(sizeof(struct filter));
	
	data->sr = sr;
	data->nyquist = sr * 0.499;
	data->x0_lp = data->x1_lp = data->x0_hp = data->x1_hp = 0.0;
	filter_compute_coeffs(data, freq);

	data->comp = compress_init(thresh, ratio, att, rel, look, sr);
	return data;
}

void filter_delete(struct filter *data) {
	free(data);
	compress_delete(data->comp);
}

float filter_process(struct filter *data, float input) {
	// lop
	float lop_out = data->a0_lp * input + data->x0_lp;
	data->x0_lp = data->a1_lp * input - data->b1 * lop_out + data->x1_lp;
	data->x1_lp = data->a2_lp * input - data->b2 * lop_out;
	// hip
	float hip_out = data->a0_hp * input + data->x0_hp;
	data->x0_hp = data->a1_hp * input - data->b1 * hip_out + data->x1_hp;
	data->x1_hp = data->a2_hp * input - data->b2 * hip_out;

	// invert hip phase
	float deesserOut = compress_process(data->comp, hip_out);
	float output = lop_out + deesserOut * -1;

	return output;
}

void filter_set_freq(struct filter *data, float freq) {
    if (freq != data->last_freq){
		filter_compute_coeffs(data, freq);
        data->last_freq = freq;
    }
}

void filter_set_compThresh(struct filter *data, float thresh) {
	compress_set_thresh(data->comp, thresh);
}


