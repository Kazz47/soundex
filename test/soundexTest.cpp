#include "gtest/gtest.h"
#include "soundex.hpp"

TEST(SoundexEncode, RetainFirstLetter) {
    string expectedVal = "A000";

    string actualVal = Soundex::encode("A000");

    ASSERT_EQ(expectedVal, actualVal);
}

TEST(SoundexEncode, ZeroPad) {
    string expectedVal = "A000";

    string actualVal = Soundex::encode("A");

    ASSERT_EQ(expectedVal, actualVal);
}

TEST(SoundexEncode, RemoveVowelLikeChars) {
    string expectedVal = "A000";

    string actualVal = Soundex::encode("AaEiOuYh");

    ASSERT_EQ(expectedVal, actualVal);
}

TEST(SoundexEncode, EncodeCharacters) {
    string expectedVal = "A123";

    string actualVal = Soundex::encode("aBcD");

    ASSERT_EQ(expectedVal, actualVal);
}

TEST(SoundexEncode, ResizeWord) {
    string expectedVal = "A123";

    string actualVal = Soundex::encode("aBcDbCd");

    ASSERT_EQ(expectedVal, actualVal);
}

TEST(SoundexEncode, EncodeAdjacentCharacters) {
    string expectedVal = "A123";

    string actualVal = Soundex::encode("AbFcGdT");

    ASSERT_EQ(expectedVal, actualVal);
}

TEST(SoundexEncode, EncodeOnceSeparatedByH) {
    string expectedVal = "A123";

    string actualVal = Soundex::encode("AbHfChGdHt");

    ASSERT_EQ(expectedVal, actualVal);
}

TEST(SoundexEncode, EncodeOnceSeparatedByW) {
    string expectedVal = "A123";

    string actualVal = Soundex::encode("AbWfCwGdWt");

    ASSERT_EQ(expectedVal, actualVal);
}

TEST(SoundexEncode, EncodeTwiceSeparatedByVowel) {
    string expectedVal = "A112";

    string actualVal = Soundex::encode("AbAfCiGdYt");

    ASSERT_EQ(expectedVal, actualVal);
}
