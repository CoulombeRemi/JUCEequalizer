/*
Remi Coulombe
tanh / atan disto
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "disto.h"
#include "utils.h"

#ifndef M_PI
#define M_PI (3.14159265358979323846264338327950288)
#endif

struct disto * disto_init(float drive, float mix, float freq, float q, float sr) {
	struct disto *data = malloc(sizeof(struct disto));
	data->drive = drive;
	data->mix = mix * 0.01;
	data->freq = freq;
	data->q = q;
	data->sr = sr;
	data->filter  = distoFltr_init(freq, sr, q);
	disto_set_drive(data, drive);
	disto_set_mix(data, mix);
	return data;
}

void disto_delete(struct disto *data) {
	free(data);
	distoFltr_delete(data->filter);
}

float disto_process(struct disto *data, float input) {
	float output_disto, output_mix;
	float compensation = scale(data->drive, 0.0f, 25.0f, 1.0f, 0.0017f, 3.0f);
	output_disto = (0.5f * M_PI) * atanf(input * data->drive);
	//output_disto = (0.5f * M_PI) * tanhf(input * data->drive);
	output_mix = ((1.0f - data->mix) * input) + (data->mix * distoFltr_process(data->filter, output_disto) * compensation);
	//distoFltr_process(data->filter, output_disto)
	return output_mix;
}

void disto_set_drive(struct disto *data, float newDrive) {
	if (newDrive < 0.0f) {
		data->drive = 0.0f;
	}
	else if (newDrive > 25.0) {
		data->drive = 25.0f;
	}
	else {
		data->drive = newDrive;
	}
}

void disto_set_mix(struct disto *data, float mix) {
	if (mix < 0.0f) {
		data->mix = 0.0f;
	}
	else if (mix > 100.0f) {
		data->mix = 100.0f;
	}
	else {
		data->mix = mix;
	}
}
void disto_set_freq(struct disto *data, float newFreq) {
	distoFltr_set_Cutoff(data->filter, newFreq);
}

void disto_set_q(struct disto *data, float newQ) {
	distoFltr_set_Q(data->filter, newQ);
}
