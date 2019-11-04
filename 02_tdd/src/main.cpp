#include <iostream>
#include "TextWrapper.h"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " [columns]" << std::endl;
        return 1;
    }

    auto columns = std::stoul(argv[1]);

    TextWrapper wrapper{columns};

    std::string line{};

    while (std::getline(std::cin, line)) {

        std::cout << std::endl << wrapper.wrap(line) << std::endl << std::endl;
    }

    return 0;
}