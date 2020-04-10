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
	struct parametricEQ *peak01[2];
	struct parametricEQ *peak02[2];
	struct parametricEQ *peak03[2];
	struct parametricEQ *peak04[2];
	struct parametricEQ *peak05[2];
	struct parametricEQ *peak06[2];
	struct parametricEQ *highShelf[2];

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
