/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class LimiterBasicAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    LimiterBasicAudioProcessorEditor (LimiterBasicAudioProcessor&);
    ~LimiterBasicAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Slider sliderThreshold;
    juce::Slider sliderRelease;
    
    juce::Label labelThreshold;
    juce::Label labelRelease;

    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentThreshold;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentRelease;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    LimiterBasicAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LimiterBasicAudioProcessorEditor)
};
