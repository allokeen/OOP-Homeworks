#include "TestIncludes.h"
#include "TextWrapper.h"

TEST(TextWrapper, Constructor) {

    TextWrapper textWrapper{};
}

TEST(TextWrapper, Constructor_DefaultNumberOfColumns) {

    TextWrapper textWrapper{};
    EXPECT_EQ(10u, textWrapper.columns());
}

TEST(TextWrapper, Constructor_CustomNumberOfColumns) {

    TextWrapper textWrapper{3u};
    EXPECT_EQ(3u, textWrapper.columns());
}

TEST(TextWrapper, OneColumn_Wrap_Empty) {

    TextWrapper textWrapper{1u};
    EXPECT_EQ("", textWrapper.wrap(""));
}

TEST(TextWrapper, OneColumn_Wrap_SingleLetter) {

    TextWrapper textWrapper{1u};
    EXPECT_EQ("a", textWrapper.wrap("a"));
}

TEST(TextWrapper, OneColumn_Wrap_TwoLetters) {

    TextWrapper textWrapper{1u};
    EXPECT_EQ("a\nb", textWrapper.wrap("ab"));
}

TEST(TextWrapper, TwoColumns_Wrap_FourLetters) {

    TextWrapper textWrapper{2u};
    EXPECT_EQ("ab\ncd", textWrapper.wrap("abcd"));
}

TEST(TextWrapper, OneColumn_Wrap_SixLetters) {

    TextWrapper textWrapper{1u};
    EXPECT_EQ("a\nb\nc\nd\ne\nf", textWrapper.wrap("abcdef"));
}

TEST(TextWrapper, TwoColumns_Wrap_SixLetters) {

    TextWrapper textWrapper{2u};
    EXPECT_EQ("ab\ncd\nef", textWrapper.wrap("abcdef"));
}

TEST(TextWrapper, OneColumn_Wrap_TwoLetters_WithSpace) {

    TextWrapper textWrapper{1u};
    EXPECT_EQ("a\nb", textWrapper.wrap("a b"));
}

TEST(TextWrapper, OneColumn_Wrap_SixLetters_WithSpace) {

    TextWrapper textWrapper{1u};
    EXPECT_EQ("a\nb\nc\nd\ne\nf", textWrapper.wrap("a b c d e f"));
}

TEST(TextWrapper, ThreeClumns_DivideBySpacesNotWords) {

    TextWrapper textWrapper{5u};
    EXPECT_EQ("foo\nbar\nbaz", textWrapper.wrap("foo bar baz"));
}

TEST(TextWrapper, ThreeClumns_DivideBySpacesNotWords_UseLastSpace) {

    TextWrapper textWrapper{7u};
    EXPECT_EQ("aa bb\ncc dd\nee", textWrapper.wrap("aa bb cc dd ee"));
}
