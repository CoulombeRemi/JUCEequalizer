/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Images  : public Component
{
public:
    //==============================================================================
    Images ();
    ~Images() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    bool hitTest (int x, int y) override;

    // Binary resources:
    static const char* pluginbg_png;
    static const int pluginbg_pngSize;
    static const char* knobRoll_png;
    static const int knobRoll_pngSize;
    static const char* redKnob_png;
    static const int redKnob_pngSize;
    static const char* yellowKnob_png;
    static const int yellowKnob_pngSize;
    static const char* greenKnob_png;
    static const int greenKnob_pngSize;
    static const char* actif_hip_png;
    static const int actif_hip_pngSize;
    static const char* actif_lop_png;
    static const int actif_lop_pngSize;
    static const char* inactif_hip_png;
    static const int inactif_hip_pngSize;
    static const char* inactif_lop_png;
    static const int inactif_lop_pngSize;
    static const char* bg_png;
    static const int bg_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Images)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

