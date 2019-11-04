#pragma once

#include <string>

class TextWrapper {
public:

    explicit TextWrapper(unsigned long providedColumns = 10u);

    unsigned long columns() const;

    std::string wrap(const std::string& string) const;

private:
    unsigned long providedColumns;
};