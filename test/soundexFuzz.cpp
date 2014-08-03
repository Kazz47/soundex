#include <cstdlib>
#include <ctime>

#include "gtest/gtest.h"
#include "soundex.hpp"

/**
 * Run all char values through
 **/
TEST(SoundexFuzz, RandomizeAll) {
    srand(time(NULL));

    for (int i = 0; i < 100000; i++) {
        unsigned int numChars = rand() % (int)(1.5 * Soundex::ENCODING_SIZE);

        string word = "";
        for (int i = 0; i < numChars; i++) {
            word += rand() % 256;
        }

        Soundex::encode(word);
    }

    SUCCEED();
}

TEST(SoundexFuzz, RandomizeChars) {
    srand(time(NULL));

    for (int i = 0; i < 100000; i++) {
        unsigned int numChars = rand() % (int)(1.5 * Soundex::ENCODING_SIZE);

        string word = "";
        for (int i = 0; i < numChars; i++) {
            word += (rand() % (126 - 32)) + 32;
        }

        Soundex::encode(word);
    }

    SUCCEED();
}
