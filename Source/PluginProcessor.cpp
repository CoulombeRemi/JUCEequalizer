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
													NormalisableRange<float>(-15.f, 15.f, 0.1f, 1.f),
													0.0f, nullptr, nullptr));
	parameters.push_back(std::make_unique<Parameter>(String("lsFreq"), String("Hz"), String(),
													NormalisableRange<float>(10.f, 20000.f, 0.5f, 0.3f),
													30.0f, nullptr, nullptr));
	parameters.push_back(std::make_unique<Parameter>(String("lsQ"), String("Q"), String(),
													NormalisableRange<float>(0.1f, 100.f, 0.5f, 0.5f),
													1.0f, nullptr, nullptr));
	// peak 01 - 100 Hz
	parameters.push_back(std::make_unique<Parameter>(String("peak01Gain"), String("Gain"), String(),
													NormalisableRange<float>(-15.f, 15.f, 0.1f, 1.f), 
													0.0f, nullptr, nullptr));
	parameters.push_back(std::make_unique<Parameter>(String("peak01Freq"), String("Hz"), String(),
													NormalisableRange<float>(10.f, 20000.f, 0.5f, 0.3f), 
													100.0f, nullptr, nullptr));
	parameters.push_back(std::make_unique<Parameter>(String("peak01Q"), String("Q"), String(),
													NormalisableRange<float>(0.1f, 100.f, 0.5f, 0.5f),
													1.0f, nullptr, nullptr));
	// peak 02 - 200 Hz
	parameters.push_back(std::make_unique<Parameter>(String("peak02Gain"), String("Gain"), String(),
													NormalisableRange<float>(-15.f, 15.f, 0.1f, 1.f),
													0.0f, nullptr, nullptr));
	parameters.push_back(std::make_unique<Parameter>(String("peak02Freq"), String("Hz"), String(),
													NormalisableRange<float>(10.f, 20000.f, 0.5f, 0.3f),
													200.0f, nullptr, nullptr));
	parameters.push_back(std::make_unique<Parameter>(String("peak02Q"), String("Q"), String(),
													NormalisableRange<float>(0.1f, 100.f, 0.5f, 0.5f),
													1.0f, nullptr, nullptr));
	// peak 03 - 1 kHz
	parameters.push_back(std::make_unique<Parameter>(String("peak03Gain"), String("Gain"), String(),
													NormalisableRange<float>(-15.f, 15.f, 0.1f, 1.f),
													0.0f, nullptr, nullptr));
	parameters.push_back(std::make_unique<Parameter>(String("peak03Freq"), String("Hz"), String(),
													NormalisableRange<float>(10.f, 20000.f, 0.5f, 0.3f),
													1000.0f, nullptr, nullptr));
	parameters.push_back(std::make_unique<Parameter>(String("peak03Q"), String("Q"), String(),
													NormalisableRange<float>(0.1f, 100.f, 0.5f, 0.5f),
													1.0f, nullptr, nullptr));
	// peak 04 - 5 kHz
	parameters.push_back(std::make_unique<Parameter>(String("peak04Gain"), String("Gain"), String(),
													NormalisableRange<float>(-15.f, 15.f, 0.1f, 1.f),
													0.0f, nullptr, nullptr));
	parameters.push_back(std::make_unique<Parameter>(String("peak04Freq"), String("Hz"), String(),
													NormalisableRange<float>(10.f, 20000.f, 0.5f, 0.3f),
													5000.0f, nullptr, nullptr));
	parameters.push_back(std::make_unique<Parameter>(String("peak04Q"), String("Q"), String(),
													NormalisableRange<float>(0.1f, 100.f, 0.5f, 0.5f),
													1.0f, nullptr, nullptr));
	// high shelft - 18 kHz
	parameters.push_back(std::make_unique<Parameter>(String("hsGain"), String("Gain"), String(),
													NormalisableRange<float>(-15.f, 15.f, 0.1f, 1.f),
													0.0f, nullptr, nullptr));
	parameters.push_back(std::make_unique<Parameter>(String("hsFreq"), String("Hz"), String(),
													NormalisableRange<float>(10.f, 20000.f, 0.5f, 0.3f),
													18000.0f, nullptr, nullptr));
	parameters.push_back(std::make_unique<Parameter>(String("hsQ"), String("Q"), String(),
													NormalisableRange<float>(0.1f, 100.f, 0.5f, 0.5f),
													1.0f, nullptr, nullptr));

	return{parameters.begin(), parameters.end()};
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

void EqualizerMusAudioProcessor::setCurrentProgram (int index)
{
}

const String EqualizerMusAudioProcessor::getProgramName (int index)
{
    return {};
}

void EqualizerMusAudioProcessor::changeProgramName (int index, const String& newName)
{
}
//==============================================================================
void EqualizerMusAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
	sr = (float)sampleRate;
	nyquist = sr * 0.499f;

	// init des in/out ?
	for (int i = 0; i < 2; i++) {
		x1[i] = x2[i] = y1[i] = y2[i] = 0.f;

		//lowShelf[i] = parametricEQ_init(30.f, float q, float gain, LOWSHELF, sr);
	}




}

void EqualizerMusAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool EqualizerMusAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
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

void EqualizerMusAudioProcessor::coeff_process_lc() {
	b0 = b2 = (1.f - c) * 0.5f;
	b1 = 1.f - c;
	a0 = 1.f + alpha;
	a1 = -2.f * c;
	a2 = 1.f - alpha;
}
void EqualizerMusAudioProcessor::coeff_process_ls() {
	float twoSqrtAAlpha = sqrtf(a * 2.0f) * alpha;
	float aMinC = (a - 1.0f) * c;
	float aAddC = (a + 1.0f) * c;
	b0 = a * ((a + 1.0f) - aMinC + twoSqrtAAlpha);
	b1 = 2.0f * a * ((a - 1.0f) - aAddC);
	b2 = a * ((a + 1.0f) - aMinC - twoSqrtAAlpha);
	a0 = 1.0f / ((a + 1.0f) + aMinC + twoSqrtAAlpha);
	a1 = -2.0f * ((a - 1.0f) + aAddC);
	a2 = (a + 1.0f) + aMinC - twoSqrtAAlpha;
}
void EqualizerMusAudioProcessor::coeff_process_hc() {
	/*
	b0 = b2 = (1.f - c) * 0.5f;
	b1 = 1.f - c;
	a0 = 1.f + alpha;
	a1 = -2.f * c;
	a2 = 1.f - alpha;
	*/
}
void EqualizerMusAudioProcessor::coeff_process_hs() {
	float twoSqrtAAlpha = sqrtf(a * 2.0f) * alpha;
	float aMinC = (a - 1.0f) * c;
	float aAddC = (a + 1.0f) * c;
	b0 = a * ((a + 1.0f) + aMinC + twoSqrtAAlpha);
	b1 = -2.0f * a * ((a - 1.0f) + aAddC);
	b2 = a * ((a + 1.0f) + aMinC - twoSqrtAAlpha);
	a0 = 1.0f / ((a + 1.0f) - aMinC + twoSqrtAAlpha);
	a1 = 2.0f * ((a - 1.0f) - aAddC);
	a2 = (a + 1.0f) - aMinC - twoSqrtAAlpha;
}
void EqualizerMusAudioProcessor::coeff_process_peak() {
	float aMulti = alpha * a;
	float aDiv = alpha / a;
	b0 = 1.f + aMulti;
	b1 = a1 = -2.f * c;
	b2 = 1.f - aMulti;
	a0 = 1.f / (1.f + aDiv);
	a2 = 1.f - aDiv;
}


void EqualizerMusAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

	for (int sample = 0; sample < buffer.getNumSamples(); sample++){

		float q = *peak01QParameter;
		float cutoff = *peak01FreqParameter;
		float dbScale = *peak01GainParameter;
		float gain = Decibels::decibelsToGain(dbScale);

		a = powf(10.f, gain / 40.f);
		w0 = (2.f * (float)M_PI) * cutoff / sr;
		c = cosf(w0);
		alpha = sinf(w0) / (2.f * q);

		coeff_process_peak(); // on call la fonction

		for (int channel = 0; channel < totalNumInputChannels; ++channel){
			// data input
			auto* channelData = buffer.getWritePointer(channel); // AKA input
			//float* outputData = buffer.getWritePointer(channel); // AKA output?

			float filter = (b0 * channelData[sample] + b1 * x1[sample] + b2 * x2[sample] - a1 * y1[sample] - a2 * y2[sample]) / a0;
			x2[channel] = x1[channel];
			x1[channel] = channelData[sample];
			y2[channel] = y1[channel];
			y1[channel] = filter;
			channelData[sample] = y1[channel];
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
    return new EqualizerMusAudioProcessorEditor (*this, parameters);
}

//==============================================================================
void EqualizerMusAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void EqualizerMusAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
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
