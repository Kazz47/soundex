#include "gtest/gtest.h"
#include "soundex.hpp"

TEST(SoundexEncode, RetainFirstLetter) {
    Soundex soundex;
    string expectedVal = "A000";

    string actualVal = soundex.encode("A000");

    ASSERT_EQ(expectedVal, actualVal);
}

TEST(SoundexEncode, ZeroPad) {
    Soundex soundex;
    string expectedVal = "A000";

    string actualVal = soundex.encode("A");

    ASSERT_EQ(expectedVal, actualVal);
}

TEST(SoundexEncode, RemoveVowelLikeChars) {
    Soundex soundex;
    string expectedVal = "A000";

    string actualVal = soundex.encode("AaEiOuYh");

    ASSERT_EQ(expectedVal, actualVal);
}

TEST(SoundexEncode, EncodeCharacters) {
    Soundex soundex;
    string expectedVal = "A123";

    string actualVal = soundex.encode("aBcD");

    ASSERT_EQ(expectedVal, actualVal);
}

TEST(SoundexEncode, ResizeWord) {
    Soundex soundex;
    string expectedVal = "A123";

    string actualVal = soundex.encode("aBcDbCd");

    ASSERT_EQ(expectedVal, actualVal);
}

TEST(SoundexEncode, EncodeAdjacentCharacters) {
    Soundex soundex;
    string expectedVal = "A123";

    string actualVal = soundex.encode("Abfcgdt");

    ASSERT_EQ(expectedVal, actualVal);
}
