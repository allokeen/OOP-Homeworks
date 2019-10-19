#pragma once

#include <string>

class TextWrapper {
public:

    int columns() const;

    std::string Wrapping( int, std::string);
};
