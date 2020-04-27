#ifndef __DISTO_H__
#define __DISTO_H__

#ifdef __cplusplus
extern "C" {
#endif

struct disto {
	float drive;
	float mix;
};

struct disto * disto_init(float thresh, float mix);

void disto_delete(struct disto *data);

float disto_process(struct disto *data, float input);

void disto_set_drive(struct disto *data, float newDrive);

// mix --> [0,1]
void disto_set_mix(struct disto *data, float mix);

#ifdef __cplusplus
}
#endif

#endif