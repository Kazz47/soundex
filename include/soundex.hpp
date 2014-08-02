#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <cassert>
#include <string>
#include <vector>
#include <locale>

using namespace std;

class Soundex {
    static const unsigned int ENCODING_SIZE = 4;
    const string CHARS_TO_DROP = "AEIOUYHW";

public:
    string encode(const string &word);

private:
    string getFirstChar(const string &word);
    string getTail(const string &word);
    string dropVowelLikeChars(const string &word);
    string zeroPad(const string &word);
};

#endif //SOUNDEX_H
