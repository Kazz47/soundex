#ifndef SOUNDEX_H
#define SOUNDEX_H

#include<string>

using namespace std;

class Soundex {
public:
    string encode(const string &word);

private:
    string zeroPad(const string &word);
};

#endif //SOUNDEX_H
