/*
  ==============================================================================

	This file was auto-generated!

	It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
EqualizerMusAudioProcessorEditor::EqualizerMusAudioProcessorEditor(EqualizerMusAudioProcessor& p, AudioProcessorValueTreeState& vts)
	: AudioProcessorEditor(&p), processor(p), valueTreeState(vts)
{
	// backgroundImg = ImageCache::getFromMemory(Images::background_jpg, Images::background_jpgSize);
	// backgroundImg = ImageCache::getFromMemory(Images::pluginbg_png, Images::pluginbg_pngSize);
	// Make sure that before the constructor has finished, you've set the
	// editor's size to whatever you need it to be.
	setSize(935, 480);
	Colour gainColor = Colour(188, 49, 28);
	Colour freqColor = Colour(230, 245, 3);
	Colour qColor = Colour(43, 106, 70);
	Colour boxbg = Colour(75,75,75);

	setLookAndFeel(&lookAndFeel);
	/*
	freqLabel.setText("FREQ", NotificationType::dontSendNotification);
	freqLabel.setJustificationType(Justification::centred);
	addAndMakeVisible(&freqLabel);
	qLabel.setText("Q", NotificationType::dontSendNotification);
	qLabel.setJustificationType(Justification::centred);
	addAndMakeVisible(&qLabel);
	gainLabel.setText("GAIN", NotificationType::dontSendNotification);
	gainLabel.setJustificationType(Justification::centred);
	addAndMakeVisible(&gainLabel);*/
	threshLab.setText("Threshold", NotificationType::dontSendNotification);
	threshLab.setJustificationType(Justification::centred);
	addAndMakeVisible(&threshLab);
	ratioLab.setText("Ratio", NotificationType::dontSendNotification);
	ratioLab.setJustificationType(Justification::centred);
	addAndMakeVisible(&ratioLab);
	attLab.setText("Attack", NotificationType::dontSendNotification);
	attLab.setJustificationType(Justification::centred);
	addAndMakeVisible(&attLab);
	relLab.setText("Release", NotificationType::dontSendNotification);
	relLab.setJustificationType(Justification::centred);
	addAndMakeVisible(&relLab);
	lhLab.setText("Look a head", NotificationType::dontSendNotification);
	lhLab.setJustificationType(Justification::centred);
	addAndMakeVisible(&lhLab);

	int textBoxSizeX = 80, textBoxSizeY = 15;


	// low shelf
	ls_gain.setLookAndFeel(&lookAndFeel);
	ls_gain.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	ls_gain.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	ls_gain.setColour(Slider::rotarySliderFillColourId, gainColor);
	addAndMakeVisible(&ls_gain);
	ls_gainAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "lsGain", ls_gain));
	ls_freq.setLookAndFeel(&lookAndFeel);
	ls_freq.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	ls_freq.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	addAndMakeVisible(&ls_freq);
	ls_freqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "lsFreq", ls_freq));
	ls_q.setLookAndFeel(&lookAndFeel);
	ls_q.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	ls_q.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	addAndMakeVisible(&ls_q);
	ls_qAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "lsQ", ls_q));
	// peak 01
	peak01_gain.setLookAndFeel(&lookAndFeel);
	peak01_gain.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	peak01_gain.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	peak01_gain.setColour(Slider::rotarySliderFillColourId, gainColor);
	addAndMakeVisible(&peak01_gain);
	peak01_gainAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak01Gain", peak01_gain));
	peak01_freq.setLookAndFeel(&lookAndFeel);
	peak01_freq.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	peak01_freq.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	addAndMakeVisible(&peak01_freq);
	peak01_freqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak01Freq", peak01_freq));
	peak01_q.setLookAndFeel(&lookAndFeel);
	peak01_q.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	peak01_q.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	addAndMakeVisible(&peak01_q);
	peak01_qAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak01Q", peak01_q));
	// peak 02
	peak02_gain.setLookAndFeel(&lookAndFeel);
	peak02_gain.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	peak02_gain.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	peak02_gain.setColour(Slider::rotarySliderFillColourId, gainColor);
	addAndMakeVisible(&peak02_gain);
	peak02_gainAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak02Gain", peak02_gain));
	peak02_freq.setLookAndFeel(&lookAndFeel);
	peak02_freq.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	peak02_freq.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	addAndMakeVisible(&peak02_freq);
	peak02_freqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak02Freq", peak02_freq));
	peak02_q.setLookAndFeel(&lookAndFeel);
	peak02_q.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	peak02_q.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	addAndMakeVisible(&peak02_q);
	peak02_qAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak02Q", peak02_q));
	// peak 03
	peak03_gain.setLookAndFeel(&lookAndFeel);
	peak03_gain.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	peak03_gain.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	peak03_gain.setColour(Slider::rotarySliderFillColourId, gainColor);
	addAndMakeVisible(&peak03_gain);
	peak03_gainAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak03Gain", peak03_gain));
	peak03_freq.setLookAndFeel(&lookAndFeel);
	peak03_freq.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	peak03_freq.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	addAndMakeVisible(&peak03_freq);
	peak03_freqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak03Freq", peak03_freq));
	peak03_q.setLookAndFeel(&lookAndFeel);
	peak03_q.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	peak03_q.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	addAndMakeVisible(&peak03_q);
	peak03_qAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak03Q", peak03_q));
	// peak 04
	peak04_gain.setLookAndFeel(&lookAndFeel);
	peak04_gain.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	peak04_gain.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	peak04_gain.setColour(Slider::rotarySliderFillColourId, gainColor);
	addAndMakeVisible(&peak04_gain);
	peak04_gainAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak04Gain", peak04_gain));
	peak04_freq.setLookAndFeel(&lookAndFeel);
	peak04_freq.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	peak04_freq.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	addAndMakeVisible(&peak04_freq);
	peak04_freqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak04Freq", peak04_freq));
	peak04_q.setLookAndFeel(&lookAndFeel);
	peak04_q.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	peak04_q.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	addAndMakeVisible(&peak04_q);
	peak04_qAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak04Q", peak04_q));
	// peak 05
	peak05_gain.setLookAndFeel(&lookAndFeel);
	peak05_gain.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	peak05_gain.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	peak05_gain.setColour(Slider::rotarySliderFillColourId, gainColor);
	addAndMakeVisible(&peak05_gain);
	peak05_gainAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak05Gain", peak05_gain));
	peak05_freq.setLookAndFeel(&lookAndFeel);
	peak05_freq.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	peak05_freq.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	addAndMakeVisible(&peak05_freq);
	peak05_freqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak05Freq", peak05_freq));
	peak05_q.setLookAndFeel(&lookAndFeel);
	peak05_q.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	peak05_q.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	addAndMakeVisible(&peak05_q);
	peak05_qAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak05Q", peak05_q));
	// peak 06
	peak06_gain.setLookAndFeel(&lookAndFeel);
	peak06_gain.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	peak06_gain.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	peak06_gain.setColour(Slider::rotarySliderFillColourId, gainColor);
	addAndMakeVisible(&peak06_gain);
	peak06_gainAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak06Gain", peak06_gain));
	peak06_freq.setLookAndFeel(&lookAndFeel);
	peak06_freq.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	peak06_freq.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	addAndMakeVisible(&peak06_freq);
	peak06_freqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak06Freq", peak06_freq));
	peak06_q.setLookAndFeel(&lookAndFeel);
	peak06_q.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	peak06_q.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	addAndMakeVisible(&peak06_q);
	peak06_qAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "peak65Q", peak06_q));
	// high shelf
	hs_gain.setLookAndFeel(&lookAndFeel);
	hs_gain.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	hs_gain.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	hs_gain.setColour(Slider::rotarySliderFillColourId, gainColor);
	addAndMakeVisible(&hs_gain);
	hs_gainAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "hsGain", hs_gain));
	hs_freq.setLookAndFeel(&lookAndFeel);
	hs_freq.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	hs_freq.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	addAndMakeVisible(&hs_freq);
	hs_freqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "hsFreq", hs_freq));
	hs_q.setLookAndFeel(&lookAndFeel);
	hs_q.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	hs_q.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	addAndMakeVisible(&hs_q);
	hs_qAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "hsQ", hs_q));


	// compressor
	comp_Thresh.setLookAndFeel(&lookAndFeel);
	comp_Thresh.setSliderStyle(Slider::LinearBarVertical);
	comp_Thresh.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	comp_Thresh.setColour(Slider::trackColourId, Colours::yellow);
	addAndMakeVisible(&comp_Thresh);
	comp_ThreshAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "compThresh", comp_Thresh));

	comp_Ratio.setLookAndFeel(&lookAndFeel);
	comp_Ratio.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
	comp_Ratio.setVelocityBasedMode(true);
	comp_Ratio.setVelocityModeParameters(0.4, 1, 0.09, false);
	comp_Ratio.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	comp_Ratio.setColour(Slider::trackColourId, boxbg);
	comp_Ratio.setColour(Slider::backgroundColourId, boxbg.withAlpha(1.0f));
	addAndMakeVisible(&comp_Ratio);
	comp_RatioAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "compRatio", comp_Ratio));

	comp_Att.setLookAndFeel(&lookAndFeel);
	comp_Att.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
	comp_Att.setVelocityBasedMode(true);
	comp_Att.setVelocityModeParameters(0.4, 1, 0.09, false);
	comp_Att.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	comp_Att.setColour(Slider::trackColourId, boxbg);
	comp_Att.setColour(Slider::backgroundColourId, boxbg.withAlpha(1.0f));
	addAndMakeVisible(&comp_Att);
	comp_AttAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "compAtt", comp_Att));

	comp_Rel.setLookAndFeel(&lookAndFeel);
	comp_Rel.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
	comp_Rel.setVelocityBasedMode(true);
	comp_Rel.setVelocityModeParameters(0.4, 1, 0.09, false);
	comp_Rel.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	comp_Rel.setColour(Slider::trackColourId, boxbg);
	comp_Rel.setColour(Slider::backgroundColourId, boxbg.withAlpha(1.0f));
	addAndMakeVisible(&comp_Rel);
	comp_RelAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "compRel", comp_Rel));

	comp_LH.setLookAndFeel(&lookAndFeel);
	comp_LH.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
	comp_LH.setVelocityBasedMode(true);
	comp_LH.setVelocityModeParameters(0.4, 1, 0.09, false);
	comp_LH.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	comp_LH.setColour(Slider::trackColourId, boxbg);
	comp_LH.setColour(Slider::backgroundColourId, boxbg);
	addAndMakeVisible(&comp_LH);
	comp_LHAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "compLH", comp_LH));


}

EqualizerMusAudioProcessorEditor::~EqualizerMusAudioProcessorEditor()
{
}

//==============================================================================
void EqualizerMusAudioProcessorEditor::paint(Graphics& g)
{
	backgroundImg = ImageCache::getFromMemory(Images::pluginbg_png, Images::pluginbg_pngSize);
	g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
	g.setColour(Colours::white);

	g.drawImage(backgroundImg, 0, 0, 935, 526, 0, 0, 935, 526);
	g.setFont(15.0f);
}

void EqualizerMusAudioProcessorEditor::resized()
{
	int freqQW = 70, freqQH = 80;
	int gainW = 80, gainH = 90;
	// posX, posY, widht, heigh

	// low shelf
	ls_freq.setBounds(50, 50, freqQW, freqQH);
	ls_q.setBounds(120, 50, freqQW, freqQH);
	ls_gain.setBounds(75, 130, gainW, gainH);
	// peak 01
	peak01_freq.setBounds(210, 140, freqQW, freqQH);
	peak01_q.setBounds(280, 140, freqQW, freqQH);
	peak01_gain.setBounds(235, 40, gainW, gainH);
	// peak 02
	peak02_freq.setBounds(370, 50, freqQW, freqQH);
	peak02_q.setBounds(440, 50, freqQW, freqQH);
	peak02_gain.setBounds(395, 130, gainW, gainH);
	// peak 03
	peak03_freq.setBounds(530, 140, freqQW, freqQH);
	peak03_q.setBounds(600, 140, freqQW, freqQH);
	peak03_gain.setBounds(555, 40, gainW, gainH);
	// second row
	// peak 04
	peak04_freq.setBounds(50, 350, freqQW, freqQH);
	peak04_q.setBounds(120, 350, freqQW, freqQH);
	peak04_gain.setBounds(75, 250, gainW, gainH);
	// peak 05
	peak05_freq.setBounds(210, 260, freqQW, freqQH);
	peak05_q.setBounds(280, 260, freqQW, freqQH);
	peak05_gain.setBounds(235, 340, gainW, gainH);
	// peak 06
	peak06_freq.setBounds(370, 350, freqQW, freqQH);
	peak06_q.setBounds(440, 350, freqQW, freqQH);
	peak06_gain.setBounds(395, 250, gainW, gainH);
	// high shelf
	hs_freq.setBounds(530, 260, freqQW, freqQH);
	hs_q.setBounds(600, 260, freqQW, freqQH);
	hs_gain.setBounds(555, 340, gainW, gainH);

	// compressor
	threshLab.setBounds(690, 50, 80, 15);
	comp_Thresh.setBounds(725, 65, 10, 250);
	ratioLab.setBounds(800, 50, 80, 15);
	comp_Ratio.setBounds(800, 65, 80, 15);
	attLab.setBounds(800, 90, 80, 15);
	comp_Att.setBounds(800, 105, 80, 15);
	relLab.setBounds(800, 130, 80, 15);
	comp_Rel.setBounds(800, 145, 80, 15);
	lhLab.setBounds(800, 170, 80, 15);
	comp_LH.setBounds(800, 185, 80, 15);
}
