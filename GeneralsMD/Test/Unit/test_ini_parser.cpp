#include <gtest/gtest.h>
#include "Common/INI.h"

TEST(INIParser, ParsesEmptyString) {
    INIParser p;
    ASSERT_NO_THROW(p.LoadString(""));
}

TEST(INIParser, ParsesSimpleKeyValue) {
    INIParser p;
    p.LoadString("Unit Infantry { MaxHealth = 100 }");
    EXPECT_EQ(p.GetInt("Infantry.MaxHealth"), 100);
}

TEST(INIParser, HandlesMissingKeys) {
    INIParser p;
    p.LoadString("Unit Infantry { MaxHealth = 100 }");
    EXPECT_EQ(p.GetInt("NonExistent.Key"), 0);
}
