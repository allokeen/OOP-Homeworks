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

    EXPECT_EQ( "", wrapper.Wrapping(1,""));                              //1 column
    EXPECT_EQ( "a", wrapper.Wrapping(1,"a"));
    EXPECT_EQ( "a\nb", wrapper.Wrapping(1,"ab"));
    EXPECT_EQ( "a\nb\nc", wrapper.Wrapping(1,"abc"));
    EXPECT_EQ( "ab\nc", wrapper.Wrapping(2, "abc"));                     //2 columns
    EXPECT_EQ( "ab\ncd", wrapper.Wrapping(2, "abcd"));
    EXPECT_EQ( "abc\ndef", wrapper.Wrapping(3, "abcdef"));               //3 columns
    EXPECT_EQ( "abcd\nefgh\nijkl", wrapper.Wrapping(4, "abcdefghijkl")); //4 columns
}

TEST( TextWrapper, WrappingTextWithSpaces)                                                             //Tekst ze spacjami
{
    auto wrapper = TextWrapper{};
    EXPECT_EQ( "a\nb", wrapper.Wrapping(1, "a b"));
    EXPECT_EQ( "Ala\nkot", wrapper.Wrapping( 3, "Ala kot"));
    EXPECT_EQ( "Pies\nAzor\nlubi\nkoty", wrapper.Wrapping(4, "Pies Azor lubi koty"));
    EXPECT_EQ( "Karol\nKamil", wrapper.Wrapping(5, "Karol  Kamil"));                        //kilka spacji między słowami
}
