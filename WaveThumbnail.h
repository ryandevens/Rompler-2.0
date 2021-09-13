/*
  ==============================================================================

    WaveThumbnail.h
    Created: 4 Apr 2020 5:47:38pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class WaveThumbnail : public Component,
                      public FileDragAndDropTarget
{
public:
    WaveThumbnail (RomplerAudioProcessor& p);
    ~WaveThumbnail();

    void paint (Graphics&) override;
    void drawMono(Graphics&, AudioBuffer<float>&);
    void drawStereo(Graphics&, AudioBuffer<float>&);
    void resized() override;
    
    bool isInterestedInFileDrag (const StringArray& files) override;
    void filesDropped (const StringArray& files, int x, int y) override;

private:
    std::vector<float> mAudioPoints;
    bool mShouldBePainting { false };
    
    String mFileName { "" };
    
    RomplerAudioProcessor& processor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveThumbnail)
};
