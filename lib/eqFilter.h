/*
	distoFiltr.h

	Antoine Lussier - R�mi Coulombe
	25 f�vrier 2020
	MUS3329

	biquad filter for waveshaper
*/
#ifndef __EQ_FILTER__
#define __EQ_FILTER__

#ifdef __cplusplus
extern "C" {
#endif

struct eqFilter {
    float sr;
    float nyquist;
	float q;
	float cutoff;
	double a0, a1, a2, b0, b1, b2;
	float x1, x2, y1, y2;
	float lastout;
	float piFreqOversr;
};
float eqFilter_process(struct eqFilter* data, float input);

struct eqFilter* eqFilter_init(float freq, float sr, float q);

void eqFilter_delete(struct eqFilter* data);

void eqFilter_set_Cutoff(struct eqFilter* data, float freq);

void eqFilter_set_Q(struct eqFilter* data, float q);

#ifdef __cplusplus
}
#endif

#endif