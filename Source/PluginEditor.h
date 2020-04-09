/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Images.h"

//==============================================================================
/**
*/
class EqualizerMusAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    EqualizerMusAudioProcessorEditor (EqualizerMusAudioProcessor&, AudioProcessorValueTreeState& vts);
    ~EqualizerMusAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
	Image backgroundImg;

	AudioProcessorValueTreeState& valueTreeState;

	Slider peak01_freq;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> freqAttachment;
	Slider peak01_q;
	Slider peak01_gain;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> gainAttachment;

    EqualizerMusAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EqualizerMusAudioProcessorEditor)
};
