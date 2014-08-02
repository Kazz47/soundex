#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <cassert>
#include <string>
#include <unordered_map>
#include <locale>

using namespace std;

class Soundex {
    static const unsigned int ENCODING_SIZE = 4;
    static const string CHARS_TO_DROP;
    static const unordered_map<char, char> CHAR_MAP;

public:
    string encode(const string &word);

private:
    string getFirstChar(const string &word);
    string getTail(const string &word);
    string encodeString(const string &word);
    string encodeChar(const char &c);
    string resize(const string &word);
};

#endif //SOUNDEX_H
