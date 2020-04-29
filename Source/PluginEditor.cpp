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
	setSize(1125, 650);
	Colour gainColor = Colour(188, 49, 28);
	Colour freqColor = Colour(230, 245, 3);
	Colour qColor = Colour(43, 106, 70);
	Colour boxbg = Colour(75,75,75);
	Colour transparent = Colour::fromFloatRGBA(0,0,0,0);

	setLookAndFeel(&lookAndFeel);
	// labels
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
	comp_out.setText("Output", NotificationType::dontSendNotification);
	comp_out.setJustificationType(Justification::centred);
	addAndMakeVisible(&comp_out);
	inGainLab.setText("INPUT", NotificationType::dontSendNotification);
	inGainLab.setJustificationType(Justification::centred);
	addAndMakeVisible(&inGainLab);
	outGainLab.setText("OUTPUT", NotificationType::dontSendNotification);
	outGainLab.setJustificationType(Justification::centred);
	addAndMakeVisible(&outGainLab);
	distoLab.setText("DRIVE", NotificationType::dontSendNotification);
	distoLab.setJustificationType(Justification::centred);
	addAndMakeVisible(&distoLab);
	drywetLab.setText("DRY-WET", NotificationType::dontSendNotification);
	drywetLab.setJustificationType(Justification::centred);
	addAndMakeVisible(&drywetLab);
	freqLab.setText("FREQ", NotificationType::dontSendNotification);
	freqLab.setJustificationType(Justification::centred);
	addAndMakeVisible(&freqLab);


	int textBoxSizeX = widthB, textBoxSizeY = 10;
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

	// disto
	disto_in.setLookAndFeel(&lookAndFeel);
	disto_in.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	disto_in.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	disto_in.setColour(Slider::trackColourId, Colours::yellow);
	addAndMakeVisible(&disto_in);
	disto_inAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "distoIn", disto_in));
	disto_amount.setLookAndFeel(&lookAndFeel);
	disto_amount.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	disto_amount.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	disto_amount.setColour(Slider::trackColourId, Colours::yellow);
	addAndMakeVisible(&disto_amount);
	disto_amountAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "distoAmount", disto_amount));
	disto_dw.setLookAndFeel(&lookAndFeel);
	disto_dw.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	disto_dw.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	disto_dw.setColour(Slider::trackColourId, Colours::yellow);
	addAndMakeVisible(&disto_dw);
	disto_dwAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "distoDW", disto_dw));
	disto_filterF.setLookAndFeel(&lookAndFeel);
	disto_filterF.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	disto_filterF.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	disto_filterF.setColour(Slider::trackColourId, Colours::yellow);
	addAndMakeVisible(&disto_filterF);
	disto_freqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "distoFreq", disto_filterF));
	disto_out.setLookAndFeel(&lookAndFeel);
	disto_out.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	disto_out.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	disto_out.setColour(Slider::trackColourId, Colours::yellow);
	addAndMakeVisible(&disto_out);
	disto_outAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "distoOut", disto_out));

	// compressor
	comp_Thresh.setLookAndFeel(&lookAndFeel);
	comp_Thresh.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	comp_Thresh.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	comp_Thresh.setColour(Slider::trackColourId, Colours::yellow);
	addAndMakeVisible(&comp_Thresh);
	comp_ThreshAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "compThresh", comp_Thresh));

	comp_Ratio.setLookAndFeel(&lookAndFeel);
	comp_Ratio.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	comp_Ratio.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	comp_Ratio.setColour(Slider::trackColourId, boxbg);
	comp_Ratio.setColour(Slider::backgroundColourId, boxbg.withAlpha(1.0f));
	addAndMakeVisible(&comp_Ratio);
	comp_RatioAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "compRatio", comp_Ratio));

	comp_Att.setLookAndFeel(&lookAndFeel);
	comp_Att.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	comp_Att.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	comp_Att.setColour(Slider::trackColourId, boxbg);
	comp_Att.setColour(Slider::backgroundColourId, boxbg.withAlpha(1.0f));
	addAndMakeVisible(&comp_Att);
	comp_AttAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "compAtt", comp_Att));

	comp_Rel.setLookAndFeel(&lookAndFeel);
	comp_Rel.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	comp_Rel.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	comp_Rel.setColour(Slider::trackColourId, boxbg);
	comp_Rel.setColour(Slider::backgroundColourId, boxbg.withAlpha(1.0f));
	addAndMakeVisible(&comp_Rel);
	comp_RelAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "compRel", comp_Rel));

	comp_LH.setLookAndFeel(&lookAndFeel);
	comp_LH.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	comp_LH.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	comp_LH.setColour(Slider::trackColourId, boxbg);
	comp_LH.setColour(Slider::backgroundColourId, boxbg);
	addAndMakeVisible(&comp_LH);
	comp_LHAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "compLH", comp_LH));
	// comp gain output
	comp_outGain.setLookAndFeel(&lookAndFeel);
	comp_outGain.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	comp_outGain.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	addAndMakeVisible(&comp_outGain);
	comp_OGAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "compOG", comp_outGain));
	// deesser
	deesser_Thresh.setLookAndFeel(&lookAndFeel);
	deesser_Thresh.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	deesser_Thresh.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	deesser_Thresh.setColour(Slider::trackColourId, Colours::yellow);
	addAndMakeVisible(&deesser_Thresh);
	deesser_ThreshAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "deesserThresh", deesser_Thresh));

	deesser_Freq.setLookAndFeel(&lookAndFeel);
	deesser_Freq.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	deesser_Freq.setTextBoxStyle(Slider::TextBoxBelow, false, textBoxSizeX, textBoxSizeY);
	deesser_Freq.setColour(Slider::trackColourId, Colours::yellow);
	addAndMakeVisible(&deesser_Freq);
	deesser_FreqAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "deesserFreq", deesser_Freq));
}

EqualizerMusAudioProcessorEditor::~EqualizerMusAudioProcessorEditor()
{
}

//==============================================================================
void EqualizerMusAudioProcessorEditor::paint(Graphics& g)
{
	backgroundImg = ImageCache::getFromMemory(Images::bg_png, Images::bg_pngSize);
	g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
	g.setColour(Colours::white);

	g.drawImage(backgroundImg, 0, 0, 1125, 650, 0, 0, 1125, 650);
	//g.setFont(1.0f);
}

void EqualizerMusAudioProcessorEditor::resized()
{
	int knob_small_w = 70, knob_small_h = 65;
	int knob_big_w = 100, knob_big_h = 95;
	int knob_bigboy_w = 125, knob_bigboy_h = 120;
	int eq_left = 30, eq_right = 120;
	// posX, posY, widht, heigh	
	// low shelf
	ls_freq.setBounds(eq_left, 15, knob_small_w, knob_small_h);
	ls_q.setBounds(eq_left, 80, knob_small_w, knob_small_h);
	ls_gain.setBounds(eq_right, 47, knob_small_w, knob_small_h);
	//ls_gain.getBounds;
	// peak 01
	peak01_freq.setBounds(eq_right, 112, knob_small_w, knob_small_h);
	peak01_q.setBounds(eq_right, 177, knob_small_w, knob_small_h);
	peak01_gain.setBounds(eq_left, 145, knob_small_w, knob_small_h);
	// peak 02

	peak02_freq.setBounds(eq_left, 210, knob_small_w, knob_small_h);
	peak02_q.setBounds(eq_left, 275, knob_small_w, knob_small_h);
	peak02_gain.setBounds(eq_right, 242, knob_small_w, knob_small_h);
	// peak 03
	peak03_freq.setBounds(eq_right, 307, knob_small_w, knob_small_h);
	peak03_q.setBounds(eq_right, 372, knob_small_w, knob_small_h);
	peak03_gain.setBounds(eq_left, 340, knob_small_w, knob_small_h);
	// second row
	// peak 04
	peak04_freq.setBounds(eq_left, 405, knob_small_w, knob_small_h);
	peak04_q.setBounds(eq_left, 470, knob_small_w, knob_small_h);
	peak04_gain.setBounds(eq_right, 437, knob_small_w, knob_small_h);
	// peak 05
	/*
	peak05_freq.setBounds(210, 260, freqQW, freqQH);
	peak05_q.setBounds(280, 260, freqQW, freqQH);
	peak05_gain.setBounds(235, 340, gainW, gainH);
	// peak 06
	peak06_freq.setBounds(370, 350, freqQW, freqQH);
	peak06_q.setBounds(440, 350, freqQW, freqQH);
	peak06_gain.setBounds(395, 250, gainW, gainH);
	*/
	// high shelf

	hs_freq.setBounds(eq_right, 502, knob_small_w, knob_small_h);
	hs_q.setBounds(eq_right, 567, knob_small_w, knob_small_h);
	hs_gain.setBounds(eq_left, 535, knob_small_w, knob_small_h);
	// disto
	int disto_mid = 341;
		inGainLab.setBounds(disto_mid - 90, 435, 80, 15);
	disto_in.setBounds(disto_mid-100, 450, knob_big_w, knob_big_h);
		outGainLab.setBounds(disto_mid+10, 435, 80, 15);
	disto_out.setBounds(disto_mid, 450, knob_big_w, knob_big_h);
		distoLab.setBounds(disto_mid - knob_bigboy_w+30, 125, 80, 15);
	disto_amount.setBounds(disto_mid - knob_bigboy_w+10, 140, knob_bigboy_w, knob_bigboy_h);
		drywetLab.setBounds(disto_mid+10, 197, 80, 15);
	disto_dw.setBounds(disto_mid-10, 212, knob_bigboy_w, knob_bigboy_h);
		freqLab.setBounds(disto_mid - 88, 285, 80, 15);
	disto_filterF.setBounds(disto_mid - 83, 300, knob_small_w, knob_small_h);
	// compressor
	int comp_mid = 562;
		threshLab.setBounds(comp_mid - 90, 65, 80, 15);
	comp_Thresh.setBounds(comp_mid-100, 80, knob_big_w, knob_big_h);
		ratioLab.setBounds(comp_mid+10, 65, 80, 15);
	comp_Ratio.setBounds(comp_mid, 80, knob_big_w, knob_big_h);
		attLab.setBounds(comp_mid - 90, 200, 80, 15);
	comp_Att.setBounds(comp_mid-100, 215, knob_big_w, knob_big_h);
		relLab.setBounds(comp_mid + 10, 200, 80, 15);
	comp_Rel.setBounds(comp_mid, 215, knob_big_w, knob_big_h);
		lhLab.setBounds(comp_mid - 90, 335, 80, 15);
	comp_LH.setBounds(comp_mid-100, 350, knob_big_w, knob_big_h);
	// comp og
	comp_out.setBounds(comp_mid+10, 335, 80, 15);
	comp_outGain.setBounds(comp_mid, 350, knob_big_w, knob_big_h);
	// deesser
	int de_mid_btn = (784 - (knob_big_w / 2)), de_mid_btn_bb = (784 - (knob_bigboy_w / 2));
	deesser_Thresh.setBounds(de_mid_btn_bb, 80, knob_bigboy_w, knob_bigboy_h);
	deesser_Freq.setBounds(de_mid_btn, 410, knob_big_w, knob_big_h);
}
