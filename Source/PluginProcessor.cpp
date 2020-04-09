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

#define M_PI 3.14159265358979323846264338327950288

//==============================================================================
EqualizerMusAudioProcessor::EqualizerMusAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
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
	sr = sampleRate;

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

void EqualizerMusAudioProcessor::lcCoeff_process() {
	b0 = b2 = (1.f - c) * 0.5;
	b1 = 1.f - c;
	a0 = 1.f + alpha;
	a1 = -2.f * c;
	a2 = 1.f - alpha;
}
void EqualizerMusAudioProcessor::hcCoeff_process() {
	b0 = b2 = (1.f - c) * 0.5;
	b1 = 1.f - c;
	a0 = 1.f + alpha;
	a1 = -2.f * c;
	a2 = 1.f - alpha;
}
void EqualizerMusAudioProcessor::peakCoeff_process() {
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

		float q = 1.f;
		float cutoff = 100.f;
		float gain = 0.5f;

		a = powf(10.f, gain / 40.f);
		w0 = (2.0 * M_PI) * cutoff / sr;
		c = cosf(w0);
		alpha = sinf(w0) / (2.f * q);

		peakCoeff_process(); // on call la fonction

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
    return new EqualizerMusAudioProcessorEditor (*this);
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
