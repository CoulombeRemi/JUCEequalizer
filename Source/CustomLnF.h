#pragma once

#include <JuceHeader.h>
#include "Images.h"


class CustomLnF : public LookAndFeel_V4
{
public:

	Colour redC = Colour(255,0,0);

	Colour light = Colour(212, 211, 224);
	Colour def = Colour(75, 75, 75);

	// Blue
	Colour darktheme = Colour(217, 228, 246);
	Colour lighttheme = Colour(113, 137, 209);
	// textBox
	Colour boxOutLine = Colour(0,0,0);
	Colour boxHighlight = Colour(255,255,255);
	// Steal
	//Colour darktheme = Colour(35, 46, 54);
	//Colour lighttheme = Colour(118, 154, 181);

	// Constructeur.
	CustomLnF() {

		setColour(ResizableWindow::backgroundColourId, darktheme);
		
		setColour(Label::textColourId, Colours::white);
		setColour(Label::textWhenEditingColourId, Colours::orange);
		setColour(Label::outlineWhenEditingColourId, Colours::green);
		setColour(Label::backgroundWhenEditingColourId, Colours::black);

		setColour(Slider::textBoxTextColourId, boxHighlight);
		setColour(Slider::textBoxOutlineColourId, boxOutLine.withAlpha(0.0f));
		setColour(Slider::textBoxHighlightColourId, lighttheme.withAlpha(0.5f));
		setColour(Slider::textBoxBackgroundColourId, def.withAlpha(0.0f));

		setColour(Slider::backgroundColourId, redC);
		setColour(Slider::rotarySliderOutlineColourId, def);
		setColour(Slider::rotarySliderFillColourId, lighttheme.withAlpha(0.25f));
		setColour(Slider::trackColourId, def);
		setColour(Slider::thumbColourId, def);

		setColour(Slider::trackColourId, def.withAlpha(0.0f));
	}

	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
		const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)override
	{
		auto bounds = Rectangle<int>((width - height) / 2.0f, y, height, height).toFloat().reduced(10);

		auto radius = jmin(bounds.getWidth(), bounds.getHeight()) / 2.0f;
		auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
		auto lineW = jmin(1.5f, radius * 0.5f);
		auto arcRadius = radius - lineW * 0.5f;

		Path background;
		background.addEllipse(bounds);
		g.setColour(slider.findColour(Slider::rotarySliderOutlineColourId));
		g.strokePath(background, PathStrokeType(lineW, PathStrokeType::curved, PathStrokeType::rounded));

		if (slider.isEnabled()) {
			Path value;
			value.addPieSegment(bounds, rotaryStartAngle, toAngle, 0.0f);
			g.setColour(slider.findColour(Slider::rotarySliderFillColourId));
			g.fillPath(value);
		}

		Path thumb;
		Point<float> thumbPoint(bounds.getCentreX() + arcRadius * std::cos(toAngle - MathConstants<float>::halfPi),
			bounds.getCentreY() + arcRadius * std::sin(toAngle - MathConstants<float>::halfPi));

		g.setColour(slider.findColour(Slider::thumbColourId));
		thumb.addLineSegment(Line<float>(bounds.getCentre(), thumbPoint), 1.5f);
		g.strokePath(thumb, PathStrokeType(lineW, PathStrokeType::curved, PathStrokeType::rounded));
	}

	void drawLinearSlider(Graphics& g, int x, int y, int width, int height,
		float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider)override{
		if (slider.isBar())
		{
			g.setColour(slider.findColour(Slider::trackColourId));
			g.fillRect(slider.isHorizontal() ? Rectangle<float>(static_cast<float> (x), y + 0.5f, sliderPos - x, height - 1.0f)
				: Rectangle<float>(x + 0.5f, sliderPos, width - 1.0f, y + (height - sliderPos)));
		}
		else
		{
			auto isTwoVal = (style == Slider::SliderStyle::TwoValueVertical || style == Slider::SliderStyle::TwoValueHorizontal);
			auto isThreeVal = (style == Slider::SliderStyle::ThreeValueVertical || style == Slider::SliderStyle::ThreeValueHorizontal);

			auto trackWidth = jmin(6.0f, slider.isHorizontal() ? height * 0.25f : width * 0.25f);

			Point<float> startPoint(slider.isHorizontal() ? x : x + width * 0.5f,
				slider.isHorizontal() ? y + height * 0.5f : height + y);

			Point<float> endPoint(slider.isHorizontal() ? width + x : startPoint.x,
				slider.isHorizontal() ? startPoint.y : y);

			Path backgroundTrack;
			backgroundTrack.startNewSubPath(startPoint);
			backgroundTrack.lineTo(endPoint);
			g.setColour(slider.findColour(Slider::backgroundColourId));
			g.strokePath(backgroundTrack, { trackWidth, PathStrokeType::curved, PathStrokeType::rounded });

			Path valueTrack;
			Point<float> minPoint, maxPoint, thumbPoint;

			if (isTwoVal || isThreeVal)
			{
				minPoint = { slider.isHorizontal() ? minSliderPos : width * 0.5f,
							 slider.isHorizontal() ? height * 0.5f : minSliderPos };

				if (isThreeVal)
					thumbPoint = { slider.isHorizontal() ? sliderPos : width * 0.5f,
								   slider.isHorizontal() ? height * 0.5f : sliderPos };

				maxPoint = { slider.isHorizontal() ? maxSliderPos : width * 0.5f,
							 slider.isHorizontal() ? height * 0.5f : maxSliderPos };
			}
			else
			{
				auto kx = slider.isHorizontal() ? sliderPos : (x + width * 0.5f);
				auto ky = slider.isHorizontal() ? (y + height * 0.5f) : sliderPos;

				minPoint = startPoint;
				maxPoint = { kx, ky };
			}

			auto thumbWidth = getSliderThumbRadius(slider);

			valueTrack.startNewSubPath(minPoint);
			valueTrack.lineTo(isThreeVal ? thumbPoint : maxPoint);
			g.setColour(slider.findColour(Slider::trackColourId));
			g.strokePath(valueTrack, { trackWidth, PathStrokeType::curved, PathStrokeType::rounded });

			if (!isTwoVal)
			{
				g.setColour(slider.findColour(Slider::thumbColourId));
				g.fillEllipse(Rectangle<float>(static_cast<float> (thumbWidth), static_cast<float> (thumbWidth)).withCentre(isThreeVal ? thumbPoint : maxPoint));
			}

			if (isTwoVal || isThreeVal)
			{
				auto sr = jmin(trackWidth, (slider.isHorizontal() ? height : width) * 0.4f);
				auto pointerColour = slider.findColour(Slider::thumbColourId);

				if (slider.isHorizontal())
				{
					drawPointer(g, minSliderPos - sr,
						jmax(0.0f, y + height * 0.5f - trackWidth * 2.0f),
						trackWidth * 2.0f, pointerColour, 2);

					drawPointer(g, maxSliderPos - trackWidth,
						jmin(y + height - trackWidth * 2.0f, y + height * 0.5f),
						trackWidth * 2.0f, pointerColour, 4);
				}
				else
				{
					drawPointer(g, jmax(0.0f, x + width * 0.5f - trackWidth * 2.0f),
						minSliderPos - trackWidth,
						trackWidth * 2.0f, pointerColour, 1);

					drawPointer(g, jmin(x + width - trackWidth * 2.0f, x + width * 0.5f), maxSliderPos - sr,
						trackWidth * 2.0f, pointerColour, 3);
				}
			}
		}
	}
	Label* createSliderTextBox(Slider& slider)
	{
		auto* l = LookAndFeel_V2::createSliderTextBox(slider);
		l->setFont(10.0f);
		if (getCurrentColourScheme() == LookAndFeel_V4::getGreyColourScheme() && (slider.getSliderStyle() == Slider::LinearBar
			|| slider.getSliderStyle() == Slider::LinearBarVertical))
		{
			l->setColour(Label::textColourId, Colours::black.withAlpha(0.7f));
		}

		return l;
	}
};