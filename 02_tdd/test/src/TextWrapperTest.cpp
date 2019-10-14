#include "TestIncludes.h"

class TextWrapper
{
public:
    int columns() const {
        return 10;
    }
    std::string Wrapping(std::string x)
    {


    }
};

TEST( TextWrapper, CreateInstance)
{
    auto wrapper = TextWrapper{};
}

TEST( TextWrapper, HasColumnsGetter)
{
    auto wrapper = TextWrapper{};

EXPECT_EQ( 10, wrapper.columns());
}

TEST( TextWrapper, TextWrapping)
{
    auto wrapper = TextWrapper{};

    EXPECT_EQ( 2, );
}

TEST( TextWrapper,  ZeroColumns )
{
    auto wrapper = TextWrapper{};

    EXPECT_EQ( "", wrapper.Wrapping(""));
    EXPECT_EQ


}





