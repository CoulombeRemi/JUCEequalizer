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

	// low shelf
	Slider ls_gain;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> ls_gainAttachment;
	Slider ls_freq;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> ls_freqAttachment;
	Slider ls_q;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> ls_qAttachment;
	// peak 01
	Slider peak01_gain;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peak01_gainAttachment;
	Slider peak01_freq;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peak01_freqAttachment;
	Slider peak01_q;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peak01_qAttachment;
	// peak 02
	Slider peak02_gain;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peak02_gainAttachment;
	Slider peak02_freq;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peak02_freqAttachment;
	Slider peak02_q;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peak02_qAttachment;
	// peak 03
	Slider peak03_gain;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peak03_gainAttachment;
	Slider peak03_freq;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peak03_freqAttachment;
	Slider peak03_q;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peak03_qAttachment;
	// peak 04
	Slider peak04_gain;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peak04_gainAttachment;
	Slider peak04_freq;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peak04_freqAttachment;
	Slider peak04_q;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peak04_qAttachment;
	// high shelf
	Slider hs_gain;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> hs_gainAttachment;
	Slider hs_freq;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> hs_freqAttachment;
	Slider hs_q;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> hs_qAttachment;

    EqualizerMusAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EqualizerMusAudioProcessorEditor)
};
