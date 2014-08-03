#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <cassert>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Soundex {
    static const unsigned int ENCODING_SIZE = 4;
    static const vector<char> VOWELS;
    static const unordered_map<char, char> CHAR_MAP;

public:
    static string encode(const string &word);

private:
    static string getFirstChar(const string &word);
    static string encodeString(const string &word);
    static string encodeChar(const char &c);
    static string resize(const string &word);
    static bool isVowel(const char &c);
};

#endif //SOUNDEX_H
