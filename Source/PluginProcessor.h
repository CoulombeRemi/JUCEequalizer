/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "parametricEQ.h"

//==============================================================================
/**
*/
class EqualizerMusAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    EqualizerMusAudioProcessor();
    ~EqualizerMusAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;




    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;


private:
	AudioProcessorValueTreeState parameters;


	struct parametricEQ *lowShelf[2];

	float lsCoeff, hsCoeff, lcCoeff, hcCoeff;
	float bpCoeff, bCoeff, nCoeff;
	float filterMemory[2];

	float sr;
	float nyquist;

	// -- peak --
	float w0, c, alpha, a;
	float a0, a1, a2, b0, b1, b2;
	float x1[2], x2[2], y1[2], y2[2];
	void coeff_process_peak();

	// variables pour coeff du lowcut?
	/*
	float w0_lc, c_lc, alpha_lc, a_lc;
	float a0_lc, a1_lc, a2_lc, b0_lc, b1_lc, b2_lc;
	float x1_lc[2], x2_lc[2], y1_lc[2], y2_lc[2];
	*/
	void coeff_process_lc();
	void coeff_process_ls();

	/*
	float w0_hc, c_hc, alpha_hc, a_hc;
	float a0_hc, a1_hc, a2_hc, b0_hc, b1_hc, b2_hc;
	float x1_hc[2], x2_hc[2], y1_hc[2], y2_hc[2];
	*/
	void coeff_process_hc();
	void coeff_process_hs();

	// low shelf
	std::atomic<float> *lsGainParameter;
	std::atomic<float> *lsFreqParameter;
	std::atomic<float> *lsQParameter;
	// peak 01
	std::atomic<float> *peak01GainParameter;
	std::atomic<float> *peak01FreqParameter;
	std::atomic<float> *peak01QParameter;
	// peak 02
	std::atomic<float> *peak02GainParameter;
	std::atomic<float> *peak02FreqParameter;
	std::atomic<float> *peak02QParameter;
	// peak 03
	std::atomic<float> *peak03GainParameter;
	std::atomic<float> *peak03FreqParameter;
	std::atomic<float> *peak03QParameter;
	// peak 04
	std::atomic<float> *peak04GainParameter;
	std::atomic<float> *peak04FreqParameter;
	std::atomic<float> *peak04QParameter;
	// peak 05
	std::atomic<float> *peak05GainParameter;
	std::atomic<float> *peak05FreqParameter;
	std::atomic<float> *peak05QParameter;
	// peak 06
	std::atomic<float> *peak06GainParameter;
	std::atomic<float> *peak06FreqParameter;
	std::atomic<float> *peak06QParameter;
	// high shelf
	std::atomic<float> *hsGainParameter;
	std::atomic<float> *hsFreqParameter;
	std::atomic<float> *hsQParameter;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EqualizerMusAudioProcessor)
};
