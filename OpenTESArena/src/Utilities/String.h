#ifndef STRING_H
#define STRING_H

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

// This static class offers various string operations and conversions.

class String
{
private:
	String() = delete;
	String(const String&) = delete;
	~String() = delete;
public:
	// Splits a string on the given character.
	static std::vector<std::string> split(const std::string &str, char separator);

	// Splits a string on whitespace.
	static std::vector<std::string> split(const std::string &str);

	// Removes all whitespace from a string.
	static std::string trim(const std::string &str);

	// Removes leading whitespace from a string.
	static std::string trimFront(const std::string &str);

	// Removes trailing whitespace from a string.
	static std::string trimBack(const std::string &str);

	// Removes new line characters from a string.
	static std::string trimLines(const std::string &str);

	// Gets the right-most extension from a string, i.e., ".txt".
	static std::string getExtension(const std::string &str);

	// Creates a new string with all 'a' characters replaced by 'b' characters.
	static std::string replace(const std::string &str, char a, char b);

	// Creates a new string with all "a" substrings replaced by "b" strings.
	static std::string replace(const std::string &str, const std::string &a,
		const std::string &b);

	// Converts each ASCII character in the given string to uppercase.
	static std::string toUppercase(const std::string &str);

	// Converts each ASCII character in the given string to lowercase.
	static std::string toLowercase(const std::string &str);

	// Converts an integral value to a hex string.
	template <typename T>
	static std::string toHexString(T value)
	{
		static_assert(std::is_integral<T>::value, "String::toHexString given non-integral type.");

		std::stringstream ss;
		ss << std::hex << value;
		return ss.str();
	}

	// Converts a floating-point value to a string with a set number of decimal places.
	template <typename T>
	static std::string fixedPrecision(T value, int precision)
	{
		static_assert(std::is_floating_point<T>::value,
			"String::fixedPrecision given non-floating-point type.");

		std::stringstream ss;
		ss << std::fixed << std::setprecision(precision) << value;
		return ss.str();
	}
};

#endif
