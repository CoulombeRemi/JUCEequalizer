/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

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


	void lcCoeff_process();
	void hcCoeff_process();
	void peakCoeff_process();

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
	float lsCoeff, hsCoeff, lcCoeff, hcCoeff;
	float bpCoeff, bCoeff, nCoeff;
	float filterMemory[2];

	float sr;
	float nyquist;

	// -- filter --
	float w0, c, alpha, a;
	// Coeff
	float a0, a1, a2, b0, b1, b2;
	float x1[2], x2[2], y1[2], y2[2];


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EqualizerMusAudioProcessor)
};