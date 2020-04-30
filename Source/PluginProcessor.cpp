/*
  ==============================================================================

	This file was auto-generated!

	It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#ifndef M_PI
#define M_PI (3.14159265358979323846264338327950288)
#endif

// 2h22m16s
static String freqValueToText(float value) { return String(value, 2) + String(" Hz"); }
static float freqTextToValue(const String& text) { return  text.getFloatValue(); }
static String qValueToText(float value) { return String(value, 2) + String(" Q"); }
static float qTextToValue(const String& text) { return text.getFloatValue(); }
static String gainValueToText(float value) { return String(value, 2) + String(" dB"); }
static float gainTextToValue(const String& text) { return text.getFloatValue(); }
static String ratioValueToText(float value) { return String(value, 2) + String(":1"); }
static float ratioTextToValue(const String& text) { return text.getFloatValue(); }
static String timeValueToText(float value) { return String(value, 2) + String(" ms"); }
static float timeTextToValue(const String& text) { return text.getFloatValue(); }


// return parameter configuration
// need to call createParameter() for initialization of the audiovaluetree....
AudioProcessorValueTreeState::ParameterLayout createParameterLayout() {
	// shortcut for AudioProcessorValueTreeState::Parameter;
	using Parameter = AudioProcessorValueTreeState::Parameter;
	//using RangedAudioParameter = AudioProcessorValueTreeState::Parameter;
	std::vector < std::unique_ptr<Parameter>> parameters;
	std::vector < std::unique_ptr<RangedAudioParameter>> btn_parameters;
	// string -> id, name in daw, description
	btn_parameters.push_back(std::make_unique<AudioParameterBool>("EQ_LOW_STATE", "hip", "false"));

	// gain values in dB
	// low shelft - 30 Hz
	parameters.push_back(std::make_unique<Parameter>(String("lsGain"), String("Gain"), String(),
		NormalisableRange<float>(-24.f, 24.f, 0.1f, 1.0f),
		0.0f, gainValueToText, gainTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("lsFreq"), String("Hz"), String(),
		NormalisableRange<float>(10.0f, 22000.0f, 0.5f, 0.3f),
		15.0f, freqValueToText, freqTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("lsQ"), String("Q"), String(),
		NormalisableRange<float>(0.1f, 100.f, 0.5f, 0.5f),
		1.0f, qValueToText, qTextToValue));
	// peak 01 - 100 Hz
	parameters.push_back(std::make_unique<Parameter>(String("peak01Gain"), String("Gain"), String(),
		NormalisableRange<float>(-24.0f, 24.0f, 0.1f, 1.f),
		0.0f, gainValueToText, gainTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak01Freq"), String("Hz"), String(),
		NormalisableRange<float>(10.0f, 22000.0f, 0.5f, 0.3f),
		40.0f, freqValueToText, freqTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak01Q"), String("Q"), String(),
		NormalisableRange<float>(0.1f, 100.f, 0.5f, 0.5f),
		1.0f, qValueToText, qTextToValue));
	// peak 02 - 300 Hz
	parameters.push_back(std::make_unique<Parameter>(String("peak02Gain"), String("Gain"), String(),
		NormalisableRange<float>(-24.0f, 24.0f, 0.1f, 1.f),
		0.0f, gainValueToText, gainTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak02Freq"), String("Hz"), String(),
		NormalisableRange<float>(10.0f, 22000.0f, 0.5f, 0.3f),
		160.0f, freqValueToText, freqTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak02Q"), String("Q"), String(),
		NormalisableRange<float>(0.1f, 100.f, 0.5f, 0.5f),
		1.0f, qValueToText, qTextToValue));
	// peak 03 - 700 kHz
	parameters.push_back(std::make_unique<Parameter>(String("peak03Gain"), String("Gain"), String(),
		NormalisableRange<float>(-24.0f, 24.0f, 0.1f, 1.f),
		0.0f, gainValueToText, gainTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak03Freq"), String("Hz"), String(),
		NormalisableRange<float>(10.0f, 22000.0f, 0.5f, 0.3f),
		550.0f, freqValueToText, freqTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak03Q"), String("Q"), String(),
		NormalisableRange<float>(0.1f, 100.f, 0.5f, 0.5f),
		1.0f, qValueToText, qTextToValue));
	// peak 04 - 1.8 kHz
	parameters.push_back(std::make_unique<Parameter>(String("peak04Gain"), String("Gain"), String(),
		NormalisableRange<float>(-24.0f, 24.0f, 0.1f, 1.f),
		0.0f, gainValueToText, gainTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak04Freq"), String("Hz"), String(),
		NormalisableRange<float>(10.0f, 22000.0f, 0.5f, 0.3f),
		2500.0f, freqValueToText, freqTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak04Q"), String("Q"), String(),
		NormalisableRange<float>(0.1f, 100.f, 0.5f, 0.5f),
		1.0f, qValueToText, qTextToValue));
	// high shelft - 18 kHz
	parameters.push_back(std::make_unique<Parameter>(String("hsGain"), String("Gain"), String(),
		NormalisableRange<float>(-24.0f, 24.0f, 0.1f, 1.f),
		0.0f, gainValueToText, gainTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("hsFreq"), String("Hz"), String(),
		NormalisableRange<float>(10.0f, 22000.0f, 0.5f, 0.3f),
		18000.0f, freqValueToText, freqTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("hsQ"), String("Q"), String(),
		NormalisableRange<float>(0.1f, 100.f, 0.5f, 0.5f),
		1.0f, qValueToText, qTextToValue));
	// disto
	parameters.push_back(std::make_unique<Parameter>(String("distoIn"), String("distoIn"), String(),
		NormalisableRange<float>(-32.0f, 18.0f, 0.1f, 1.f),
		0.0f, gainValueToText, gainTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("distoAmount"), String("Amount"), String(),
		NormalisableRange<float>(0.0f, 100.0f, 0.1f, 1.f),
		0.0f, nullptr, nullptr));
	parameters.push_back(std::make_unique<Parameter>(String("distoDW"), String("dryWet"), String(),
		NormalisableRange<float>(0.0f, 100.0f, 0.1f, 1.f),
		0.0f, nullptr, nullptr));
	parameters.push_back(std::make_unique<Parameter>(String("distoFreq"), String("Hz"), String(),
		NormalisableRange<float>(20.0f, 20000.0f, 0.1f, 1.f),
		10000.0f, freqValueToText, freqTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("distoOut"), String("distoOut"), String(),
		NormalisableRange<float>(-32.0f, 18.0f, 0.1f, 1.f),
		0.0f, gainValueToText, gainTextToValue));
	// compressor
	parameters.push_back(std::make_unique<Parameter>(String("compThresh"), String("Threshold"), String(),
		NormalisableRange<float>(-70.0f, 0.0f, 0.1f, 1.f),
		0.0f, gainValueToText, gainTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("compRatio"), String("Ratio"), String(),
		NormalisableRange<float>(1.0f, 20.0f, 0.1f, 1.f),
		1.0f, ratioValueToText, ratioTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("compAtt"), String("Att."), String(),
		NormalisableRange<float>(1.0f, 150.0f, 0.1f, 1.f),
		5.0f, timeValueToText, timeTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("compRel"), String("Rel."), String(),
		NormalisableRange<float>(1.0f, 250.0f, 0.1f, 1.f),
		50.0f, timeValueToText, timeTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("compLH"), String(" ms"), String(),
		NormalisableRange<float>(0.5f, 10.0f, 0.1f, 1.f),
		5.0f, timeValueToText, timeTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("compMakeup"), String("makeup"), String(),
		NormalisableRange<float>(0.0f, 100.0f, 0.1f, 1.f),
		0.0f, gainValueToText, gainTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("compOG"), String("out gain"), String(),
		NormalisableRange<float>(-18.0f, 18.0f, 0.1f, 1.f),
		0.0f, gainValueToText, gainTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("compDW"), String("dryWet"), String(),
		NormalisableRange<float>(0.0f, 100.0f, 0.1f, 1.f),
		100.0f, nullptr, nullptr));
	// deesser
	parameters.push_back(std::make_unique<Parameter>(String("deesserThresh"), String("Threshold"), String(),
		NormalisableRange<float>(-70.0f, 0.0f, 0.1f, 1.f),
		0.0f, gainValueToText, gainTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("deesserFreq"), String("Hz"), String(),
		NormalisableRange<float>(2000.0f, 16000.0f, 0.5f, 0.3f),
		5500.0f, freqValueToText, freqTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("deesserOut"), String("out gain"), String(),
		NormalisableRange<float>(-18.0f, 18.0f, 0.1f, 1.f),
		0.0f, gainValueToText, gainTextToValue));
	return{ parameters.begin(), parameters.end() };
}


//==============================================================================
EqualizerMusAudioProcessor::EqualizerMusAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
	: AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
		.withInput("Input", AudioChannelSet::stereo(), true)
#endif
		.withOutput("Output", AudioChannelSet::stereo(), true)
#endif
	),
#endif
	parameters(*this, nullptr, Identifier(JucePlugin_Name), createParameterLayout())
{
	// low shelf
	lsGainParameter = parameters.getRawParameterValue("lsGain");
	lsFreqParameter = parameters.getRawParameterValue("lsFreq");
	lsQParameter = parameters.getRawParameterValue("lsQ");
	// peak 01
	peak01GainParameter = parameters.getRawParameterValue("peak01Gain");
	peak01FreqParameter = parameters.getRawParameterValue("peak01Freq");
	peak01QParameter = parameters.getRawParameterValue("peak01Q");
	// peak 02
	peak02GainParameter = parameters.getRawParameterValue("peak02Gain");
	peak02FreqParameter = parameters.getRawParameterValue("peak02Freq");
	peak02QParameter = parameters.getRawParameterValue("peak02Q");
	// peak 03
	peak03GainParameter = parameters.getRawParameterValue("peak03Gain");
	peak03FreqParameter = parameters.getRawParameterValue("peak03Freq");
	peak03QParameter = parameters.getRawParameterValue("peak03Q");
	// peak 04
	peak04GainParameter = parameters.getRawParameterValue("peak04Gain");
	peak04FreqParameter = parameters.getRawParameterValue("peak04Freq");
	peak04QParameter = parameters.getRawParameterValue("peak04Q");
	// high shelf
	hsGainParameter = parameters.getRawParameterValue("hsGain");
	hsFreqParameter = parameters.getRawParameterValue("hsFreq");
	hsQParameter = parameters.getRawParameterValue("hsQ");
	// disto
	distoInParameter = parameters.getRawParameterValue("distoIn");
	distoAmountParameter = parameters.getRawParameterValue("distoAmount");
	distoDWParameter = parameters.getRawParameterValue("distoDW");
	distoFreqParameter = parameters.getRawParameterValue("distoFreq");
	distoOutParameter = parameters.getRawParameterValue("distoOut");
	// compressor
	compThreshParameter = parameters.getRawParameterValue("compThresh");
	compRatioParameter = parameters.getRawParameterValue("compRatio");
	compAttParameter = parameters.getRawParameterValue("compAtt");
	compRelParameter = parameters.getRawParameterValue("compRel");
	compLHParameter = parameters.getRawParameterValue("compLH");
	compOGParameter = parameters.getRawParameterValue("compOG");
	compDWParameter = parameters.getRawParameterValue("compDW");
	// deesser
	deesserThreshParameter = parameters.getRawParameterValue("deesserThresh");
	deesserFreqParameter = parameters.getRawParameterValue("deesserFreq");
	deesserOutParameter = parameters.getRawParameterValue("deesserOut");
}

EqualizerMusAudioProcessor::~EqualizerMusAudioProcessor()
{
}

//==============================================================================
const String EqualizerMusAudioProcessor::getName() const
{
	return JucePlugin_Name;
}

bool EqualizerMusAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
	return true;
#else
	return false;
#endif
}

bool EqualizerMusAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
	return true;
#else
	return false;
#endif
}

bool EqualizerMusAudioProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
	return true;
#else
	return false;
#endif
}

double EqualizerMusAudioProcessor::getTailLengthSeconds() const
{
	return 0.0;
}

int EqualizerMusAudioProcessor::getNumPrograms()
{
	return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
				// so this should be at least 1, even if you're not really implementing programs.
}

int EqualizerMusAudioProcessor::getCurrentProgram()
{
	return 0;
}

void EqualizerMusAudioProcessor::setCurrentProgram(int index)
{
}

const String EqualizerMusAudioProcessor::getProgramName(int index)
{
	return {};
}

void EqualizerMusAudioProcessor::changeProgramName(int index, const String& newName)
{
}
//==============================================================================
void EqualizerMusAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
	// init
	for (int i = 0; i < 2; i++) {
		// EQ
		//highPass[i] = filter_init(*lsFreqParameter, sampleRate, LOWPASS, 0.0f, 1.0f, 5.0f, 150.0f, 5.0f);
		//highPass[i] = filter_init(*lsFreqParameter, sampleRate, HIGHPASS, 0.0f, 1.0f, 5.0f, 150.0f, 5.0f);
		lowShelf[i] = parametricEQ_init(*lsFreqParameter, *lsQParameter, *lsGainParameter, LOWSHELF, sampleRate);
		peak01[i] = parametricEQ_init(*peak01FreqParameter, *peak01QParameter, *peak01GainParameter, PEAK, sampleRate);
		peak02[i] = parametricEQ_init(*peak02FreqParameter, *peak02QParameter, *peak02GainParameter, PEAK, sampleRate);
		peak03[i] = parametricEQ_init(*peak03FreqParameter, *peak03QParameter, *peak03GainParameter, PEAK, sampleRate);
		peak04[i] = parametricEQ_init(*peak04FreqParameter, *peak04QParameter, *peak04GainParameter, PEAK, sampleRate);
		highShelf[i] = parametricEQ_init(*hsFreqParameter, *hsQParameter, *hsGainParameter, HIGHSHELF, sampleRate);
		// disto
		dist[i] = disto_init(*distoAmountParameter, *distoDWParameter, *distoFreqParameter, 4.0f, sampleRate);
		// Comp
		compressor[i] = compress_init(*compThreshParameter, *compRatioParameter, *compAttParameter, *compRelParameter, *compLHParameter, sampleRate, *compDWParameter);
		//deesser
		float deesserOut = *deesserOutParameter;
		deesser[i] = filter_init(*deesserFreqParameter, sampleRate, CROSS,*deesserThreshParameter, 4.0f, 5.0f, 250.0f, 5.0f, Decibels::decibelsToGain(deesserOut));
	}
}

void EqualizerMusAudioProcessor::releaseResources()
{
	// When playback stops, you can use this as an opportunity to free up any
	// spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool EqualizerMusAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
	ignoreUnused(layouts);
	return true;
#else
	// This is the place where you check if the layout is supported.
	// In this template code we only support mono or stereo.
	if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
		&& layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
		return false;

	// This checks if the input layout matches the output layout
#if ! JucePlugin_IsSynth
	if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
		return false;
#endif

	return true;
#endif
}
#endif

void EqualizerMusAudioProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	ScopedNoDenormals noDenormals;
	auto totalNumInputChannels = getTotalNumInputChannels();
	auto totalNumOutputChannels = getTotalNumOutputChannels();

	for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
		buffer.clear(i, 0, buffer.getNumSamples());

	for (int channel = 0; channel < totalNumInputChannels; ++channel) {
		auto* channelData = buffer.getWritePointer(channel); // AKA input
		// low shelf
		parametricEQ_set_filterT(lowShelf[channel], LOWSHELF);
		parametricEQ_set_freq(lowShelf[channel], *lsFreqParameter);
		parametricEQ_set_q(lowShelf[channel], *lsQParameter);
		parametricEQ_set_gain(lowShelf[channel], *lsGainParameter);
		// peak 01
		parametricEQ_set_filterT(peak01[channel], PEAK);
		parametricEQ_set_freq(peak01[channel], *peak01FreqParameter);
		parametricEQ_set_q(peak01[channel], *peak01QParameter);
		parametricEQ_set_gain(peak01[channel], *peak01GainParameter);
		// peak 02
		parametricEQ_set_filterT(peak02[channel], PEAK);
		parametricEQ_set_freq(peak02[channel], *peak02FreqParameter);
		parametricEQ_set_q(peak02[channel], *peak02QParameter);
		parametricEQ_set_gain(peak02[channel], *peak02GainParameter);
		// peak 03
		parametricEQ_set_filterT(peak03[channel], PEAK);
		parametricEQ_set_freq(peak03[channel], *peak03FreqParameter);
		parametricEQ_set_q(peak03[channel], *peak03QParameter);
		parametricEQ_set_gain(peak03[channel], *peak03GainParameter);
		// peak 04
		parametricEQ_set_filterT(peak04[channel], PEAK);
		parametricEQ_set_freq(peak04[channel], *peak04FreqParameter);
		parametricEQ_set_q(peak04[channel], *peak04QParameter);
		parametricEQ_set_gain(peak04[channel], *peak04GainParameter);
		// high shelf
		parametricEQ_set_filterT(highShelf[channel], HIGHSHELF);
		parametricEQ_set_freq(highShelf[channel], *hsFreqParameter);
		parametricEQ_set_q(highShelf[channel], *hsQParameter);
		parametricEQ_set_gain(highShelf[channel], *hsGainParameter);
		// disto
		disto_set_drive(dist[channel], *distoAmountParameter);
		disto_set_mix(dist[channel], *distoDWParameter);
		disto_set_freq(dist[channel], *distoFreqParameter);
		// compressor
		compress_set_thresh(compressor[channel], *compThreshParameter);
		compress_set_ratio(compressor[channel], *compRatioParameter);
		compress_set_attack(compressor[channel], *compAttParameter);
		compress_set_release(compressor[channel], *compRelParameter);
		compress_set_lookahead(compressor[channel], *compLHParameter);
		compress_set_mix(compressor[channel], *compDWParameter);
		// deesser
		float deesserOut = *deesserOutParameter;
		filter_set_compThresh(deesser[channel], *deesserThreshParameter);
		filter_set_freq(deesser[channel], *deesserFreqParameter);
		filter_set_outGain(deesser[channel], Decibels::decibelsToGain(deesserOut));

		for (int i = 0; i < getBlockSize(); i++) {
			// Eq
			channelData[i] = parametricEQ_process(lowShelf[channel], channelData[i]);
			channelData[i] = parametricEQ_process(peak01[channel], channelData[i]);
			channelData[i] = parametricEQ_process(peak02[channel], channelData[i]);
			channelData[i] = parametricEQ_process(peak03[channel], channelData[i]);
			channelData[i] = parametricEQ_process(peak04[channel], channelData[i]);
			channelData[i] = parametricEQ_process(highShelf[channel], channelData[i]);
			// disto
			float in_gain = *distoInParameter, out_gain = *distoOutParameter;
			channelData[i] = disto_process(dist[channel], channelData[i] * Decibels::decibelsToGain(in_gain)) * Decibels::decibelsToGain(out_gain);
			// compressor with output control
			float gain = *compOGParameter;
			channelData[i] = compress_process(compressor[channel], channelData[i]) * Decibels::decibelsToGain(gain);
			// deesser
			channelData[i] = filter_process(deesser[channel], channelData[i]);
		}

	}
}

//==============================================================================
bool EqualizerMusAudioProcessor::hasEditor() const
{
	return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* EqualizerMusAudioProcessor::createEditor()
{
	return new EqualizerMusAudioProcessorEditor(*this, parameters);
}

//==============================================================================
void EqualizerMusAudioProcessor::getStateInformation(MemoryBlock& destData)
{
	// You should use this method to store your parameters in the memory block.
	// You could do that either as raw data, or use the XML or ValueTree classes
	// as intermediaries to make it easy to save and load complex data.
}

void EqualizerMusAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
	// You should use this method to restore your parameters from this memory block,
	// whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new EqualizerMusAudioProcessor();
}
