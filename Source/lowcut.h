/*
  ==============================================================================

    lowcut.h
    Created: 8 Apr 2020 7:58:45pm
    Author:  Remi PC

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class lowcut    : public Component
{
public:
    lowcut();
    ~lowcut();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (lowcut)
};
