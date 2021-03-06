#ifndef OPTIONS_PARSER_H
#define OPTIONS_PARSER_H

#include <memory>
#include <string>

// The options parser uses the options text file to generate an options object.

class Options;

class OptionsParser
{
private:
	// Graphics.
	static const std::string SCREEN_WIDTH_KEY;
	static const std::string SCREEN_HEIGHT_KEY;
	static const std::string FULLSCREEN_KEY;
	static const std::string TARGET_FPS_KEY;
	static const std::string RESOLUTION_SCALE_KEY;
	static const std::string VERTICAL_FOV_KEY;
	static const std::string LETTERBOX_ASPECT_KEY;
	static const std::string CURSOR_SCALE_KEY;
	static const std::string MODERN_INTERFACE_KEY;

	// Input.
	static const std::string H_SENSITIVITY_KEY;
	static const std::string V_SENSITIVITY_KEY;

    // Sound.
    static const std::string MUSIC_VOLUME_KEY;
    static const std::string SOUND_VOLUME_KEY;
	static const std::string SOUNDFONT_KEY;
    static const std::string SOUND_CHANNELS_KEY;

	// Miscellaneous.
	static const std::string ARENA_PATH_KEY;
	static const std::string SKIP_INTRO_KEY;
	static const std::string SHOW_DEBUG_KEY;

	OptionsParser() = delete;
	OptionsParser(const OptionsParser&) = delete;
	~OptionsParser() = delete;
public:
	static const std::string FILENAME;

	// Reads in the options text file and converts it to an Options object.
	static std::unique_ptr<Options> parse(const std::string &filename);

	// Overwrite the options text file with a new options object.
	static void save(const Options &options);
};

#endif
