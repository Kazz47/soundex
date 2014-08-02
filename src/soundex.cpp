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
    encoded += encodeString(getTail(word));
    return resize(encoded);
}

string Soundex::getFirstChar(const string &word) {
    return string(1, toupper(word.at(0)));
}

string Soundex::getTail(const string &word) {
    return word.substr(1);
}

string Soundex::encodeString(const string &word) {
    string encoded = "";
    for (char c : word) {
        string nextLetter = encodeChar(c);
        if (nextLetter != string(1, encoded.back())) {
            encoded += nextLetter;
        }
    }
    return encoded;
}

string Soundex::encodeChar(const char &c) {
    unordered_map<char, char>::const_iterator it = CHAR_MAP.find(toupper(c));
    if (it != CHAR_MAP.end()) {
        return string(1, it->second);
    }
    return "";
}

string Soundex::resize(const string &word)  {
    string newWord = word;
    if (newWord.length() > ENCODING_SIZE) {
        newWord = newWord.substr(0, ENCODING_SIZE);
    } else {
       unsigned int zerosNeeded = ENCODING_SIZE - newWord.length();
       newWord = newWord + string(zerosNeeded, '0');
    }
    return newWord;
}