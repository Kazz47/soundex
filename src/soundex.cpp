#include "soundex.hpp"

const string Soundex::CHARS_TO_DROP = "AEIOUYHW";
const unordered_map<char, char> Soundex::CHAR_MAP = {
    {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
    {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'Z', '2'}, {'Z', '2'},
    {'D', '3'}, {'T', '3'},
    {'l', '4'},
    {'m', '5'}, {'n', '5'},
    {'r', '6'}
};

string Soundex::encode(const string &word) {
    string encoded = getFirstChar(word);
    encoded += encodeString(dropVowelLikeChars(getTail(word)));
    return zeroPad(encoded);
}

string Soundex::getFirstChar(const string &word) {
    return string(1, toupper(word.at(0)));
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

string Soundex::encodeString(const string &word) {
    string encoded = "";
    for (char c : word) {
        encoded += encodeChar(c);
    }
    return encoded;
}

string Soundex::encodeChar(const char &c) {
    unordered_map<char, char>::const_iterator it = CHAR_MAP.find(c);
    if (it != CHAR_MAP.end()) {
        return string(1, it->second);
    }
    return "";
}

string Soundex::zeroPad(const string &word)  {
    assert(word.length() <= ENCODING_SIZE);
    unsigned int zerosNeeded = ENCODING_SIZE - word.length();
    return word + string(zerosNeeded, '0');
}