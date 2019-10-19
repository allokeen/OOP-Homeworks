#include "TestIncludes.h"
#include "TextWrapper.h"

TEST(TextWrapper, CreateInstance) {

    auto wrapper = TextWrapper{};
}

TEST(TextWrapper, HasColumnsGetter) {

    auto wrapper = TextWrapper{};

    EXPECT_EQ(10, wrapper.columns());
}

TEST( TextWrapper, WrappingGivenText)
{
    auto wrapper = TextWrapper{};

    EXPECT_EQ( "", wrapper.Wrapping(1,""));                     //1 column
    EXPECT_EQ( "a", wrapper.Wrapping(1,"a"));
    EXPECT_EQ( "a\nb", wrapper.Wrapping(1,"ab"));
    EXPECT_EQ( "ab\nc", wrapper.Wrapping(2, "abc"));            //2 columns
    EXPECT_EQ( "ab\ncd", wrapper.Wrapping(2, "abcd"));
}

TEST( TextWrapper, WrappingTextWithSpaces)
{
    auto wrapper = TextWrapper{};
    EXPECT_EQ( "a\nb", wrapper.Wrapping(1, "a b"));

}
