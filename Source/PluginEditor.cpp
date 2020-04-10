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

	// low shelf
	ls_gain.setSliderStyle(Slider::LinearBarVertical);
	ls_gain.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	ls_gain.setPopupDisplayEnabled(true, true, this);
	ls_gain.setTextValueSuffix(" dB");
	ls_gainAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "lsGain", ls_gain));
	addAndMakeVisible(&ls_gain);
	ls_freq.setSliderStyle(Slider::LinearBarVertical);
	ls_freq.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	ls_freq.setPopupDisplayEnabled(true, true, this);
	ls_freq.setTextValueSuffix(" Hz");
	ls_freqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "lsFreq", ls_freq));
	addAndMakeVisible(&ls_freq);
	ls_q.setSliderStyle(Slider::LinearBarVertical);
	ls_q.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	ls_q.setPopupDisplayEnabled(true, true, this);
	ls_q.setTextValueSuffix(" Q");
	ls_qAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "lsQ", ls_q));
	addAndMakeVisible(&ls_q);
	// peak 01
	peak01_gain.setSliderStyle(Slider::LinearBarVertical);
	peak01_gain.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak01_gain.setPopupDisplayEnabled(true, true, this);
	peak01_gain.setTextValueSuffix(" dB");
	peak01_gainAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak01Gain", peak01_gain));
	addAndMakeVisible(&peak01_gain);
	peak01_freq.setSliderStyle(Slider::LinearBarVertical);
	peak01_freq.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak01_freq.setPopupDisplayEnabled(true, true, this);
	peak01_freq.setTextValueSuffix(" Hz");
	peak01_freqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak01Freq", peak01_freq));
	addAndMakeVisible(&peak01_freq);
	peak01_q.setSliderStyle(Slider::LinearBarVertical);
	peak01_q.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak01_q.setPopupDisplayEnabled(true, true, this);
	peak01_q.setTextValueSuffix(" Q");
	peak01_qAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak01Q", peak01_q));
	addAndMakeVisible(&peak01_q);
	// peak 02
	peak02_gain.setSliderStyle(Slider::LinearBarVertical);
	peak02_gain.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak02_gain.setPopupDisplayEnabled(true, true, this);
	peak02_gain.setTextValueSuffix(" dB");
	peak02_gainAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak02Gain", peak02_gain));
	addAndMakeVisible(&peak02_gain);
	peak02_freq.setSliderStyle(Slider::LinearBarVertical);
	peak02_freq.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak02_freq.setPopupDisplayEnabled(true, true, this);
	peak02_freq.setTextValueSuffix(" Hz");
	peak02_freqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak02Freq", peak02_freq));
	addAndMakeVisible(&peak02_freq);
	peak02_q.setSliderStyle(Slider::LinearBarVertical);
	peak02_q.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak02_q.setPopupDisplayEnabled(true, true, this);
	peak02_q.setTextValueSuffix(" Q");
	peak02_qAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak02Q", peak02_q));
	addAndMakeVisible(&peak02_q);
	// peak 03
	peak03_gain.setSliderStyle(Slider::LinearBarVertical);
	peak03_gain.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak03_gain.setPopupDisplayEnabled(true, true, this);
	peak03_gain.setTextValueSuffix(" dB");
	peak03_gainAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak03Gain", peak03_gain));
	addAndMakeVisible(&peak03_gain);
	peak03_freq.setSliderStyle(Slider::LinearBarVertical);
	peak03_freq.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak03_freq.setPopupDisplayEnabled(true, true, this);
	peak03_freq.setTextValueSuffix(" Hz");
	peak03_freqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak03Freq", peak03_freq));
	addAndMakeVisible(&peak03_freq);
	peak03_q.setSliderStyle(Slider::LinearBarVertical);
	peak03_q.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak03_q.setPopupDisplayEnabled(true, true, this);
	peak03_q.setTextValueSuffix(" Q");
	peak03_qAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak03Q", peak03_q));
	addAndMakeVisible(&peak03_q);
	// peak 04
	peak04_gain.setSliderStyle(Slider::LinearBarVertical);
	peak04_gain.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak04_gain.setPopupDisplayEnabled(true, true, this);
	peak04_gain.setTextValueSuffix(" dB");
	peak04_gainAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak04Gain", peak04_gain));
	addAndMakeVisible(&peak04_gain);
	peak04_freq.setSliderStyle(Slider::LinearBarVertical);
	peak04_freq.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak04_freq.setPopupDisplayEnabled(true, true, this);
	peak04_freq.setTextValueSuffix(" Hz");
	peak04_freqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak04Freq", peak04_freq));
	addAndMakeVisible(&peak04_freq);
	peak04_q.setSliderStyle(Slider::LinearBarVertical);
	peak04_q.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak04_q.setPopupDisplayEnabled(true, true, this);
	peak04_q.setTextValueSuffix(" Q");
	peak04_qAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak04Q", peak04_q));
	addAndMakeVisible(&peak04_q);
	// peak 05
	peak05_gain.setSliderStyle(Slider::LinearBarVertical);
	peak05_gain.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak05_gain.setPopupDisplayEnabled(true, true, this);
	peak05_gain.setTextValueSuffix(" dB");
	peak05_gainAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak05Gain", peak05_gain));
	addAndMakeVisible(&peak05_gain);
	peak05_freq.setSliderStyle(Slider::LinearBarVertical);
	peak05_freq.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak05_freq.setPopupDisplayEnabled(true, true, this);
	peak05_freq.setTextValueSuffix(" Hz");
	peak05_freqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak05Freq", peak05_freq));
	addAndMakeVisible(&peak05_freq);
	peak05_q.setSliderStyle(Slider::LinearBarVertical);
	peak05_q.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak05_q.setPopupDisplayEnabled(true, true, this);
	peak05_q.setTextValueSuffix(" Q");
	peak05_qAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak05Q", peak05_q));
	addAndMakeVisible(&peak05_q);
	// peak 06
	peak06_gain.setSliderStyle(Slider::LinearBarVertical);
	peak06_gain.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak06_gain.setPopupDisplayEnabled(true, true, this);
	peak06_gain.setTextValueSuffix(" dB");
	peak06_gainAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak06Gain", peak06_gain));
	addAndMakeVisible(&peak06_gain);
	peak06_freq.setSliderStyle(Slider::LinearBarVertical);
	peak06_freq.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak06_freq.setPopupDisplayEnabled(true, true, this);
	peak06_freq.setTextValueSuffix(" Hz");
	peak06_freqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak06Freq", peak06_freq));
	addAndMakeVisible(&peak06_freq);
	peak06_q.setSliderStyle(Slider::LinearBarVertical);
	peak06_q.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	peak06_q.setPopupDisplayEnabled(true, true, this);
	peak06_q.setTextValueSuffix(" Q");
	peak06_qAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak65Q", peak06_q));
	addAndMakeVisible(&peak06_q);
	// high shelf
	hs_gain.setSliderStyle(Slider::LinearBarVertical);
	hs_gain.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	hs_gain.setPopupDisplayEnabled(true, true, this);
	hs_gain.setTextValueSuffix(" dB");
	hs_gainAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "hsGain", hs_gain));
	addAndMakeVisible(&hs_gain);
	hs_freq.setSliderStyle(Slider::LinearBarVertical);
	hs_freq.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	hs_freq.setPopupDisplayEnabled(true, true, this);
	hs_freq.setTextValueSuffix(" Hz");
	hs_freqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "hsFreq", hs_freq));
	addAndMakeVisible(&hs_freq);
	hs_q.setSliderStyle(Slider::LinearBarVertical);
	hs_q.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	hs_q.setPopupDisplayEnabled(true, true, this);
	hs_q.setTextValueSuffix(" Q");
	hs_qAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "hsQ", hs_q));
	addAndMakeVisible(&hs_q);
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
	// low shelf - ls_gain - ls_freq - ls_q
	ls_freq.setBounds(50, 20, 20, getHeight() - 50);
	ls_q.setBounds(80, 20, 20, getHeight() - 50);
	ls_gain.setBounds(110,20,20, getHeight() - 50);
	// peak 01
	peak01_freq.setBounds(150,20, 20, getHeight() - 50);
	peak01_q.setBounds(180,20,20,getHeight()-50);
	peak01_gain.setBounds(210, 20, 20, getHeight() - 50);
	// peak 02
	peak02_freq.setBounds(250, 20, 20, getHeight() - 50);
	peak02_q.setBounds(280, 20, 20, getHeight() - 50);
	peak02_gain.setBounds(310, 20, 20, getHeight() - 50);
	// peak 03
	peak03_freq.setBounds(350, 20, 20, getHeight() - 50);
	peak03_q.setBounds(380, 20, 20, getHeight() - 50);
	peak03_gain.setBounds(410, 20, 20, getHeight() - 50);
	// peak 04
	peak04_freq.setBounds(450, 20, 20, getHeight() - 50);
	peak04_q.setBounds(480, 20, 20, getHeight() - 50);
	peak04_gain.setBounds(510, 20, 20, getHeight() - 50);
	// peak 05
	peak05_freq.setBounds(550, 20, 20, getHeight() - 50);
	peak05_q.setBounds(580, 20, 20, getHeight() - 50);
	peak05_gain.setBounds(610, 20, 20, getHeight() - 50);
	// peak 06
	peak06_freq.setBounds(650, 20, 20, getHeight() - 50);
	peak06_q.setBounds(680, 20, 20, getHeight() - 50);
	peak06_gain.setBounds(710, 20, 20, getHeight() - 50);
	// high shelf
	hs_freq.setBounds(750, 20, 20, getHeight() - 50);
	hs_q.setBounds(780, 20, 20, getHeight() - 50);
	hs_gain.setBounds(810,20, 20, getHeight() - 50);
}
