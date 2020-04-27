#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "disto.h"
#ifndef M_PI
#define M_PI (3.14159265358979323846264338327950288)
#endif

struct disto * disto_init(float drive, float mix) {
	struct disto *data = malloc(sizeof(struct disto));
	data->drive = drive;
	data->mix = mix;
	return data;
}

void disto_delete(struct disto *data) {
	free(data);
}

float disto_process(struct disto *data, float input) {
	float output_disto, output_mix;
	/*
	if (input > data->threshold || input < (-1 * data->threshold)) {
		out = fabs(fabs(fmod(input - data->threshold, data->threshold * 4.0f)) - data->threshold * 2.0f) - data->threshold;
	}*/
	/*
	if (input < data->threshold) {
		out = input;
	}else if (input > data->threshold && input <= 1.0f) {
		out = data->threshold + (input - data->threshold) / (1.0f + pow(((input - data->threshold) / (1.0f - data->threshold)), 2));
	}else if (input > 1.0f) {
		out = (data->threshold + 1.0f) * 0.5f;
	}*/
	//output_disto = (0.5f * M_PI) * atanf(input * data->drive);
	output_disto = (0.5f * M_PI) * tanhf(input * data->drive);
	output_mix = (1.0f - data->mix) * input + data->mix * output_disto;

	return output_mix;
}

void disto_set_drive(struct disto *data, float newDrive) {
	if (newDrive < 0.0f) {
		data->drive = 0.0f;
	}
	else if (newDrive > 1.0) {
		data->drive = 1.0f;
	}
	else {
		data->drive = newDrive;
	}
}

void disto_set_mix(struct disto *data, float mix) {
	if (mix < 0.0f) {
		data->mix = 0.0f;
	}
	else if (mix > 1.0f) {
		data->mix = 1.0f;
	}
	else {
		data->mix = mix;
	}
}