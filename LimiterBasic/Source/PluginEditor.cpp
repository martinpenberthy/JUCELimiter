/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LimiterBasicAudioProcessorEditor::LimiterBasicAudioProcessorEditor (LimiterBasicAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    addAndMakeVisible(sliderThreshold);
    addAndMakeVisible(sliderRelease);
    
    
    sliderThreshold.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    sliderThreshold.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 76, 38);
    sliderThreshold.setDoubleClickReturnValue(true, 0.0f);
    labelThreshold.attachToComponent(&sliderThreshold, false);
    labelThreshold.setText("Thresh(dB)", juce::dontSendNotification);
    
    sliderRelease.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    sliderRelease.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 76, 38);
    sliderRelease.setDoubleClickReturnValue(true, 0.0f);
    labelRelease.attachToComponent(&sliderRelease, false);
    labelRelease.setText("Release(ms)", juce::dontSendNotification);
    
    
    sliderAttachmentThreshold = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "THRESHOLD", sliderThreshold);
    sliderAttachmentRelease = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "RELEASE", sliderRelease);
}

LimiterBasicAudioProcessorEditor::~LimiterBasicAudioProcessorEditor()
{
}

//==============================================================================
void LimiterBasicAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);

}

void LimiterBasicAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    sliderThreshold.setBounds(getWidth()/2 - 100, getHeight()/2 - 100, 100, 100);
    sliderRelease.setBounds(getWidth()/2, getHeight()/2 - 100, 100, 100);
    
}
