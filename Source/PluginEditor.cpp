/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
EqualizerMusAudioProcessorEditor::EqualizerMusAudioProcessorEditor (EqualizerMusAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), processor (p), valueTreeState(vts)
{
	//backgroundImg = ImageCache::getFromMemory(Images::background_jpg, Images::background_jpgSize);
	backgroundImg = ImageCache::getFromMemory(Images::pluginbg_png, Images::pluginbg_pngSize);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (935, 526);

	

	peak01_gain.setSliderStyle(Slider::LinearBarVertical);
	peak01_gain.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak01_gain.setPopupDisplayEnabled(true, true, this);
	peak01_gain.setTextValueSuffix(" dB");
	gainAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peakGain", peak01_gain));
	addAndMakeVisible(&peak01_gain);

	peak01_freq.setSliderStyle(Slider::LinearBarVertical);
	peak01_freq.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak01_freq.setPopupDisplayEnabled(true, true, this);
	peak01_freq.setTextValueSuffix(" Hz");
	freqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peakFreq", peak01_freq));
	addAndMakeVisible(&peak01_freq);

	peak01_q.setSliderStyle(Slider::LinearBarVertical);
	peak01_q.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak01_q.setPopupDisplayEnabled(true, true, this);
	peak01_q.setTextValueSuffix(" Q");
	freqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peakQ", peak01_q));
	addAndMakeVisible(&peak01_q);

}

EqualizerMusAudioProcessorEditor::~EqualizerMusAudioProcessorEditor()
{
}

//==============================================================================
void EqualizerMusAudioProcessorEditor::paint (Graphics& g)
{
	g.drawImage(backgroundImg, 0,0,935,526,0,0,935,526);
	

    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("ok", getLocalBounds(), Justification::centred, 1);
}

void EqualizerMusAudioProcessorEditor::resized()
{
	peak01_gain.setBounds(50, 20, 20, getHeight() - 50);
	peak01_freq.setBounds(100,20,20,getHeight()-50);
	peak01_q.setBounds(150, 20, 20, getHeight() - 50);
}
