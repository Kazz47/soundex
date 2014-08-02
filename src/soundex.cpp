#include "soundex.hpp"

string Soundex::encode(const string &word) {
    string encoded = getFirstChar(word) + dropVowelLikeChars(getTail(word));
    return zeroPad(encoded);
}

string Soundex::getFirstChar(const string &word) {
    return word.substr(0, 1);
}

string Soundex::getTail(const string &word) {
    return word.substr(1);
}

string Soundex::dropVowelLikeChars(const string &word) {
    string newWord = "";
    locale loc;
    for (int i = 0; i < word.length(); i++) {
        char upperChar = toupper(word[i], loc);
        bool contains = false;
        for (int j = 0; j < CHARS_TO_DROP.length(); j++) {
            if (upperChar == CHARS_TO_DROP[j]) {
                contains = true;
                break;
            }
        }
        if (!contains) {
            newWord += upperChar;
        }
    }
    return newWord;
}

string Soundex::zeroPad(const string &word)  {
    assert(word.length() <= ENCODING_SIZE);
    unsigned int zerosNeeded = ENCODING_SIZE - word.length();
    return word + string(zerosNeeded, '0');
}