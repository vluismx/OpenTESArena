#ifndef IMG_FILE_H
#define IMG_FILE_H

#include <cstdint>
#include <memory>
#include <string>

#include "../Media/Palette.h"

// An IMG file can have one of a few formats; either with a header that determines
// properties, or without a header (either raw or a wall). Some IMGs also have a
// built-in palette, which they may or may not use eventually.

class IMGFile
{
private:
	std::unique_ptr<uint32_t[]> pixels;
	int width, height;

	// Reads the palette from an IMG file and writes into the given palette reference.
	static void readPalette(const uint8_t *paletteData, Palette &dstPalette);
public:
	// Loads an IMG from file. Uses the given palette unless it is null, then it 
	// refers to the IMG's built-in palette instead if it has one.
	IMGFile(const std::string &filename, const Palette *palette);
	~IMGFile();

	// Extracts the palette from an IMG file and writes it into the given palette
	// reference. Causes an error if the IMG file doesn't have a palette.
	static void extractPalette(const std::string &filename, Palette &dstPalette);

	// Gets the width of the IMG in pixels.
	int getWidth() const;

	// Gets the height of the IMG in pixels.
	int getHeight() const;

	// Gets a pointer to the pixel data for the IMG.
	uint32_t *getPixels() const;
};

#endif
