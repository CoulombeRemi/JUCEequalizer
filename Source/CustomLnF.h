#pragma once

#include <JuceHeader.h>
#include "Images.h"

/*******************************************
Red
*******************************************/
class CustomLnFRed : public LookAndFeel_V4
{
public:
	Colour def = Colour(75, 75, 75);
	CustomLnFRed() {
		setColour(Label::backgroundColourId, def.withAlpha(0.0f));

		setColour(Slider::trackColourId, def.withAlpha(0.0f));
	}

	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
		const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)override
	{
		// https://forum.juce.com/t/skinning-the-slider-replacing-knob-and-slider-track-with-pngs/12026/8

		Image strip;
		strip = ImageCache::getFromMemory(Images::knobred_png, Images::knobred_pngSize);
		const double fractRotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum()); //value between 0 and 1 for current amount of rotation
		const int nFrames = strip.getHeight() / strip.getWidth(); // number of frames for vertical film strip
		const int frameIdx = (int)ceil(fractRotation * ((double)nFrames - 1.0)); // current index from 0 --> nFrames-1

		const float radius = jmin(width / 2.0f, height / 2.0f);
		const float centreX = x + width * 0.5f;
		const float centreY = y + height * 0.5f;
		const float rx = centreX - radius - 1.0f;
		const float ry = centreY - radius /* - 1.0f*/;

		g.drawImage(strip, 
			(int)rx, (int)ry, strip.getWidth(), strip.getWidth(),
			0, frameIdx*strip.getWidth(), strip.getWidth(), strip.getWidth());
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

/*******************************************
 Yellow
*******************************************/
class CustomLnFBlue : public LookAndFeel_V4
{
public:
	CustomLnFBlue() {}
	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
		const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)override
	{
		Image strip;
		strip = ImageCache::getFromMemory(Images::knobble_png, Images::knobble_pngSize);
		const double fractRotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum());
		const int nFrames = strip.getHeight() / strip.getWidth();
		const int frameIdx = (int)ceil(fractRotation * ((double)nFrames - 1.0));
		const float radius = jmin(width / 2.0f, height / 2.0f);
		const float centreX = x + width * 0.5f;
		const float centreY = y + height * 0.5f;
		const float rx = centreX - radius - 1.0f;
		const float ry = centreY - radius /* - 1.0f*/;
		g.drawImage(strip,
			(int)rx, (int)ry, strip.getWidth(), strip.getWidth(),
			0, frameIdx*strip.getWidth(), strip.getWidth(), strip.getWidth());
	}
	Label* createSliderTextBox(Slider& slider){
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
/*******************************************
 Green
*******************************************/
class CustomLnFGreen : public LookAndFeel_V4
{
public:
	CustomLnFGreen() {}
	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
		const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)override
	{
		Image strip;
		strip = ImageCache::getFromMemory(Images::knobgre_png, Images::knobgre_pngSize);
		const double fractRotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum());
		const int nFrames = strip.getHeight() / strip.getWidth();
		const int frameIdx = (int)ceil(fractRotation * ((double)nFrames - 1.0));
		const float radius = jmin(width / 2.0f, height / 2.0f);
		const float centreX = x + width * 0.5f;
		const float centreY = y + height * 0.5f;
		const float rx = centreX - radius - 1.0f;
		const float ry = centreY - radius /* - 1.0f*/;
		g.drawImage(strip,
			(int)rx, (int)ry, strip.getWidth(), strip.getWidth(),
			0, frameIdx*strip.getWidth(), strip.getWidth(), strip.getWidth());
	}
	Label* createSliderTextBox(Slider& slider) {
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
/*******************************************
 white
*******************************************/
class CustomLnFWhite : public LookAndFeel_V4
{
public:
	CustomLnFWhite() {}
	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
		const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)override
	{
		Image strip;
		strip = ImageCache::getFromMemory(Images::knobwht_png, Images::knobwht_pngSize);
		const double fractRotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum());
		const int nFrames = strip.getHeight() / strip.getWidth();
		const int frameIdx = (int)ceil(fractRotation * ((double)nFrames - 1.0));
		const float radius = jmin(width / 2.0f, height / 2.0f);
		const float centreX = x + width * 0.5f;
		const float centreY = y + height * 0.5f;
		const float rx = centreX - radius - 1.0f;
		const float ry = centreY - radius /* - 1.0f*/;
		g.drawImage(strip,
			(int)rx, (int)ry, strip.getWidth(), strip.getWidth(),
			0, frameIdx*strip.getWidth(), strip.getWidth(), strip.getWidth());
	}
	Label* createSliderTextBox(Slider& slider) {
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
/*******************************************
 black
*******************************************/
class CustomLnFBlack : public LookAndFeel_V4
{
public:
	CustomLnFBlack() {}
	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
		const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)override
	{
		Image strip;
		strip = ImageCache::getFromMemory(Images::knobbla_png, Images::knobbla_pngSize);
		const double fractRotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum());
		const int nFrames = strip.getHeight() / strip.getWidth();
		const int frameIdx = (int)ceil(fractRotation * ((double)nFrames - 1.0));
		const float radius = jmin(width / 2.0f, height / 2.0f);
		const float centreX = x + width * 0.5f;
		const float centreY = y + height * 0.5f;
		const float rx = centreX - radius - 1.0f;
		const float ry = centreY - radius /* - 1.0f*/;
		g.drawImage(strip,
			(int)rx, (int)ry, strip.getWidth(), strip.getWidth(),
			0, frameIdx*strip.getWidth(), strip.getWidth(), strip.getWidth());
	}
	Label* createSliderTextBox(Slider& slider) {
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
/*******************************************
 Moog
*******************************************/
class CustomLnFMoog : public LookAndFeel_V4
{
public:
	CustomLnFMoog() {}
	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
		const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)override
	{
		Image strip;
		strip = ImageCache::getFromMemory(Images::moogKn_png, Images::moogKn_pngSize);
		const double fractRotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum());
		const int nFrames = strip.getHeight() / strip.getWidth();
		const int frameIdx = (int)ceil(fractRotation * ((double)nFrames - 1.0));
		const float radius = jmin(width / 2.0f, height / 2.0f);
		const float centreX = x + width * 0.5f;
		const float centreY = y + height * 0.5f;
		const float rx = centreX - radius - 1.0f;
		const float ry = centreY - radius /* - 1.0f*/;
		g.drawImage(strip,
			(int)rx, (int)ry, strip.getWidth(), strip.getWidth(),
			0, frameIdx*strip.getWidth(), strip.getWidth(), strip.getWidth());
	}
	Label* createSliderTextBox(Slider& slider) {
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