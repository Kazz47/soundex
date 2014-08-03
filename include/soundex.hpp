#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <cassert>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Soundex encoding class.
 * This class can be used to encode American English names into phonetically compareable strings.
 * For example, the names 'Rupert' and 'Robert' will be encoded to the same phonetically independent string since their pronunciations are very similar.
 */
class Soundex {
public:
    static const unsigned int ENCODING_SIZE = 4; // The length of the encoded strhing.

    /**
     * Encode the provided string.
     * The provided string is turned into a four character code.
     * @param word A constant string.
     * @result The encoded string.
     */
    static string encode(const string &word);

private:
    static const vector<char> VOWELS; // Vector to hold an array of vowels.
    static const unordered_map<char, char> CHAR_MAP; // Hash map to hold letters and their encoded value.

    /**
     * Encode an string with the soundex algorithm.
     * @param word A constant string.
     * @result An encoded string.
     */
    static string encodeString(const string &word);

    /**
     * Get the encoded value for a single character.
     * @param c Character to encode.
     * @result String of the encoded character.
     */
    static string encodeChar(const char &c);

    /**
     * Resize a word to match the ENCODED_SIZE.
     * @param word A constant string.
     * @result The input string trimmed or zero padded.
     */
    static string resize(const string &word);

    /**
     * Check if a character is a vowel.
     * @param c Character to check.
     * @result True if vowel, false otherwise.
     */
    static bool isVowel(const char &c);
};

#endif //SOUNDEX_H
