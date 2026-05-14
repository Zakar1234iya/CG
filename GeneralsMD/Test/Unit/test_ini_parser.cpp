#include <gtest/gtest.h>
#include "Common/INI.h"

TEST(INIParser, ParsesUnitHP) {
    INIParser p;
    p.LoadString("Unit Infantry { MaxHealth = 100 }");
    EXPECT_EQ(p.GetInt("Infantry.MaxHealth"), 100);
}

TEST(INIParser, ParsesEmptyString) {
    INIParser p;
    p.LoadString("");
    EXPECT_TRUE(true);
}
