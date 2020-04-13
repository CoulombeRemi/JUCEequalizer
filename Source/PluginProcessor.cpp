/*
  ==============================================================================

	This file was auto-generated!

	It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

/*

https://forum.juce.com/t/multiple-iirfilters/20331/9

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

// return parameter configuration
// need to call createParameter() for initialization of the audiovaluetree....
AudioProcessorValueTreeState::ParameterLayout createParameterLayout() {
	// shortcut for AudioProcessorValueTreeState::Parameter;
	using Parameter = AudioProcessorValueTreeState::Parameter;
	std::vector < std::unique_ptr<Parameter>> parameters;
	// string -> id, name in daw, description
	// gain values in dB

	// low shelft - 30 Hz
	parameters.push_back(std::make_unique<Parameter>(String("lsGain"), String("Gain"), String(),
		NormalisableRange<float>(-24.f, 24.f, 0.1f, 1.0f),
		0.0f, gainValueToText, gainTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("lsFreq"), String("Hz"), String(),
		NormalisableRange<float>(10.0f, 22000.0f, 0.5f, 0.3f),
		30.0f, freqValueToText, freqTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("lsQ"), String("Q"), String(),
		NormalisableRange<float>(0.1f, 100.f, 0.5f, 0.5f),
		1.0f, qValueToText, qTextToValue));
	// peak 01 - 100 Hz
	parameters.push_back(std::make_unique<Parameter>(String("peak01Gain"), String("Gain"), String(),
		NormalisableRange<float>(-24.0f, 24.0f, 0.1f, 1.f),
		0.0f, gainValueToText, gainTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak01Freq"), String("Hz"), String(),
		NormalisableRange<float>(10.0f, 22000.0f, 0.5f, 0.3f),
		100.0f, freqValueToText, freqTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak01Q"), String("Q"), String(),
		NormalisableRange<float>(0.1f, 100.f, 0.5f, 0.5f),
		1.0f, qValueToText, qTextToValue));
	// peak 02 - 300 Hz
	parameters.push_back(std::make_unique<Parameter>(String("peak02Gain"), String("Gain"), String(),
		NormalisableRange<float>(-24.0f, 24.0f, 0.1f, 1.f),
		0.0f, gainValueToText, gainTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak02Freq"), String("Hz"), String(),
		NormalisableRange<float>(10.0f, 22000.0f, 0.5f, 0.3f),
		300.0f, freqValueToText, freqTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak02Q"), String("Q"), String(),
		NormalisableRange<float>(0.1f, 100.f, 0.5f, 0.5f),
		1.0f, qValueToText, qTextToValue));
	// peak 03 - 700 kHz
	parameters.push_back(std::make_unique<Parameter>(String("peak03Gain"), String("Gain"), String(),
		NormalisableRange<float>(-24.0f, 24.0f, 0.1f, 1.f),
		0.0f, gainValueToText, gainTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak03Freq"), String("Hz"), String(),
		NormalisableRange<float>(10.0f, 22000.0f, 0.5f, 0.3f),
		700.0f, freqValueToText, freqTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak03Q"), String("Q"), String(),
		NormalisableRange<float>(0.1f, 100.f, 0.5f, 0.5f),
		1.0f, qValueToText, qTextToValue));
	// peak 04 - 1.8 kHz
	parameters.push_back(std::make_unique<Parameter>(String("peak04Gain"), String("Gain"), String(),
		NormalisableRange<float>(-24.0f, 24.0f, 0.1f, 1.f),
		0.0f, gainValueToText, gainTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak04Freq"), String("Hz"), String(),
		NormalisableRange<float>(10.0f, 22000.0f, 0.5f, 0.3f),
		1800.0f, freqValueToText, freqTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak04Q"), String("Q"), String(),
		NormalisableRange<float>(0.1f, 100.f, 0.5f, 0.5f),
		1.0f, qValueToText, qTextToValue));
	// peak 05 - 4 kHz
	parameters.push_back(std::make_unique<Parameter>(String("peak05Gain"), String("Gain"), String(),
		NormalisableRange<float>(-24.0f, 24.0f, 0.1f, 1.f),
		0.0f, gainValueToText, gainTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak05Freq"), String("Hz"), String(),
		NormalisableRange<float>(10.0f, 22000.0f, 0.5f, 0.3f),
		4000.0f, freqValueToText, freqTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak05Q"), String("Q"), String(),
		NormalisableRange<float>(0.1f, 100.f, 0.5f, 0.5f),
		1.0f, qValueToText, qTextToValue));
	// peak 06 - 8 kHz
	parameters.push_back(std::make_unique<Parameter>(String("peak06Gain"), String("Gain"), String(),
		NormalisableRange<float>(-24.0f, 24.0f, 0.1f, 1.f),
		0.0f, gainValueToText, gainTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak06Freq"), String("Hz"), String(),
		NormalisableRange<float>(10.0f, 22000.0f, 0.5f, 0.3f),
		8000.0f, freqValueToText, freqTextToValue));
	parameters.push_back(std::make_unique<Parameter>(String("peak06Q"), String("Q"), String(),
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
	// peak 05
	peak05GainParameter = parameters.getRawParameterValue("peak05Gain");
	peak05FreqParameter = parameters.getRawParameterValue("peak05Freq");
	peak05QParameter = parameters.getRawParameterValue("peak05Q");
	// peak 06
	peak06GainParameter = parameters.getRawParameterValue("peak06Gain");
	peak06FreqParameter = parameters.getRawParameterValue("peak06Freq");
	peak06QParameter = parameters.getRawParameterValue("peak06Q");
	// high shelf
	hsGainParameter = parameters.getRawParameterValue("hsGain");
	hsFreqParameter = parameters.getRawParameterValue("hsFreq");
	hsQParameter = parameters.getRawParameterValue("hsQ");
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
		lowShelf[i] = parametricEQ_init(*lsFreqParameter, *lsQParameter, *lsGainParameter, LOWSHELF, sampleRate);
		peak01[i] = parametricEQ_init(*peak01FreqParameter, *peak01QParameter, *peak01GainParameter, PEAK, sampleRate);
		peak02[i] = parametricEQ_init(*peak02FreqParameter, *peak02QParameter, *peak02GainParameter, PEAK, sampleRate);
		peak03[i] = parametricEQ_init(*peak03FreqParameter, *peak03QParameter, *peak03GainParameter, PEAK, sampleRate);
		peak04[i] = parametricEQ_init(*peak04FreqParameter, *peak04QParameter, *peak04GainParameter, PEAK, sampleRate);
		peak05[i] = parametricEQ_init(*peak05FreqParameter, *peak05QParameter, *peak05GainParameter, PEAK, sampleRate);
		peak06[i] = parametricEQ_init(*peak06FreqParameter, *peak06QParameter, *peak06GainParameter, PEAK, sampleRate);
		highShelf[i] = parametricEQ_init(*hsFreqParameter, *hsQParameter, *hsGainParameter, HIGHSHELF, sampleRate);
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
		// peak 05
		parametricEQ_set_filterT(peak05[channel], PEAK);
		parametricEQ_set_freq(peak05[channel], *peak05FreqParameter);
		parametricEQ_set_q(peak05[channel], *peak05QParameter);
		parametricEQ_set_gain(peak05[channel], *peak05GainParameter);
		// peak 06
		parametricEQ_set_filterT(peak06[channel], PEAK);
		parametricEQ_set_freq(peak06[channel], *peak06FreqParameter);
		parametricEQ_set_q(peak06[channel], *peak06QParameter);
		parametricEQ_set_gain(peak06[channel], *peak06GainParameter);
		// high shelf
		parametricEQ_set_filterT(highShelf[channel], HIGHSHELF);
		parametricEQ_set_freq(highShelf[channel], *hsFreqParameter);
		parametricEQ_set_q(highShelf[channel], *hsQParameter);
		parametricEQ_set_gain(highShelf[channel], *hsGainParameter);

		for (int i = 0; i < getBlockSize(); i++) {
			channelData[i] = parametricEQ_process(lowShelf[channel], channelData[i]);
			channelData[i] = parametricEQ_process(peak01[channel], channelData[i]);
			channelData[i] = parametricEQ_process(peak02[channel], channelData[i]);
			channelData[i] = parametricEQ_process(peak03[channel], channelData[i]);
			channelData[i] = parametricEQ_process(peak04[channel], channelData[i]);
			channelData[i] = parametricEQ_process(peak05[channel], channelData[i]);
			channelData[i] = parametricEQ_process(peak06[channel], channelData[i]);
			channelData[i] = parametricEQ_process(highShelf[channel], channelData[i]);
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
