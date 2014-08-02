#include "soundex.hpp"

string Soundex::encode(const string &word) {
    string encoded = word;
    return zeroPad(word);
}

string Soundex::zeroPad(const string &word)  {
    unsigned int zerosNeeded = ENCODING_SIZE - word.length();
    return word + string(zerosNeeded, '0');
}