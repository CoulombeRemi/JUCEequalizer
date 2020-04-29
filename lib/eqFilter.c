/*
	distoFiltr.c

	Antoine Lussier - Rémi Coulombe
	25 février 2020
	MUS3329

	biquad filter for waveshaper
*/

#include <stdlib.h>
#include <math.h>
#include "eqFilter.h"

#ifndef M_PI
#define M_PI (3.1415926)
#endif


static void coeff_process(struct eqFilter* data, float freq, float q) {
	// cutoff verification
	if (freq > data->nyquist){
		data->cutoff = data->nyquist;
	}else if (freq < 20.0) {
		data->cutoff = 20.0;
	}else{
		data->cutoff = freq;
	}
	// Q verification
	if (q > 100.0) {
		data->q = 100.0;
	}else if (q < 0.1) {
		data->q = 0.1;
	}else {
		data->q = q;
	}
	// Coeff
	float w0 = (2.0 * M_PI) * data->cutoff / data->sr;
	float c = cos(w0);
	float alpha = sin(w0) / (2.0 * data->q);
	data->b0 = data->b2 = (1.0 - c) * 0.5;
	data->b1 = 1.0 - c;
	data->a0 = 1.0 + alpha;
	data->a1 = -2.0 * c;
	data->a2 = 1.0 - alpha;
}

struct eqFilter* eqFilter_init(float freq, float sr, float q) {
	struct eqFilter *data = malloc(sizeof(struct eqFilter));
	data->sr = sr;
	data->nyquist = sr * 0.499;
	data->q = q;
	data->x1 = data->x2 = data->y1 = data->y2 = 0.0;
	coeff_process(data, freq, q);
	return data;
}

void eqFilter_delete(struct eqFilter* data) {
	free(data);
}

float eqFilter_process(struct eqFilter* data, float input) {
	float output = (data->b0 * input + data->b1 * data->x1 + data->b2 * data->x2 - data->a1 * data->y1 - data->a2 * data->y2) / data->a0;
	data->x2 = data->x1;
	data->x1 = input;
	data->y2 = data->y1;
	data->y1 = output;
	return output;
}

void eqFilter_set_Cutoff(struct eqFilter* data, float freq) {
	if (freq != data->lastout) {
		coeff_process(data, freq, data->q);
		data->lastout = freq;
	}
}

void eqFilter_set_Q(struct eqFilter* data, float q) {
	if (q != data->q) {
		coeff_process(data, data->cutoff, q);
		data->q = q;
	}
}

