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
#include "CustomLnF.h"

//==============================================================================
/**
*/
class EqualizerMusAudioProcessorEditor : public AudioProcessorEditor
{
public:
	EqualizerMusAudioProcessorEditor(EqualizerMusAudioProcessor&, AudioProcessorValueTreeState& vts);
	~EqualizerMusAudioProcessorEditor();

	//==============================================================================
	void paint(Graphics&) override;
	void resized() override;

private:

	int widthB = 70;

	CustomLnF lookAndFeel;
	Image backgroundImg;
	Label inGainLab, outGainLab, distoLab, drywetLab, freqLab;
	Label threshLab, ratioLab, attLab, relLab, lhLab, comp_out;
	

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
	// peak 05
	Slider peak05_gain;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peak05_gainAttachment;
	Slider peak05_freq;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peak05_freqAttachment;
	Slider peak05_q;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peak05_qAttachment;
	// peak 06
	Slider peak06_gain;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peak06_gainAttachment;
	Slider peak06_freq;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peak06_freqAttachment;
	Slider peak06_q;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peak06_qAttachment;
	// high shelf
	Slider hs_gain;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> hs_gainAttachment;
	Slider hs_freq;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> hs_freqAttachment;
	Slider hs_q;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> hs_qAttachment;
	// disto
	Slider disto_in;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> disto_inAttachment;
	Slider disto_amount;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> disto_amountAttachment;
	Slider disto_dw;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> disto_dwAttachment;
	Slider disto_filterF;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> disto_freqAttachment;
	Slider disto_out;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> disto_outAttachment;
	// compressor
	Slider comp_Thresh;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> comp_ThreshAttachment;
	Slider comp_Ratio;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> comp_RatioAttachment;
	Slider comp_Att;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> comp_AttAttachment;
	Slider comp_Rel;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> comp_RelAttachment;
	Slider comp_LH;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> comp_LHAttachment;
	// gain output
	Slider comp_outGain;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> comp_OGAttachment;
	// deesser
	Slider deesser_Thresh;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> deesser_ThreshAttachment;
	Slider deesser_Freq;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> deesser_FreqAttachment;

	EqualizerMusAudioProcessor& processor;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EqualizerMusAudioProcessorEditor)
};
