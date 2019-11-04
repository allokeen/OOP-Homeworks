#include "TextWrapper.h"

TextWrapper::TextWrapper(unsigned long providedColumns)
    : providedColumns(providedColumns) {

}

unsigned long TextWrapper::columns() const {
    return providedColumns;
}

std::string TextWrapper::wrap(const std::string &string) const {

    if (string.size() > providedColumns) {

        std::size_t divisionStart = providedColumns;
        std::size_t divisionStop = providedColumns;

        auto space = string.rfind(' ', providedColumns);

        if (space != std::string::npos) {

            divisionStart = space;
            divisionStop = divisionStart + 1;
        }

        return string.substr(0, divisionStart) + "\n" + wrap(string.substr(divisionStop));
    }

    return string;
}
