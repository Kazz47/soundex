#include "soundex.hpp"

const vector<char> Soundex::VOWELS = {'A', 'E', 'I', 'O', 'U', 'Y'};
const unordered_map<char, char> Soundex::CHAR_MAP = {
    {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
    {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'Z', '2'}, {'Z', '2'},
    {'D', '3'}, {'T', '3'},
    {'L', '4'},
    {'M', '5'}, {'N', '5'},
    {'R', '6'}
};

string Soundex::encode(const string &word) {
    string encoded = encodeString(word);
    return resize(encoded);
}

string Soundex::encodeString(const string &word) {
    string encoded = string(1, toupper(word[0]));
    char prevChar = 0;
    string prevEncoding = encodeChar(encoded[0]);
    for (int i = 1; i < word.length(); i++) {
        char c = toupper(word[i]);
        string nextEncoding = encodeChar(c);
        if (nextEncoding != "" && (isVowel(prevChar) || nextEncoding != prevEncoding)) {
            encoded += nextEncoding;
            prevEncoding = nextEncoding;
        }
        prevChar = c;
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

bool Soundex::isVowel(const char &c) {
    for (char vowel : VOWELS) {
        if (c == vowel) {
            return true;
        }
    }
    return false;
}
