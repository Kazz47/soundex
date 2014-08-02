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
