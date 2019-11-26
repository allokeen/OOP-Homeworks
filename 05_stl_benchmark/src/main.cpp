#include <iostream>
#include "Dummy.h"
#include "Small.h";

int main(int argc, char* argv[])
{
    Dummy dummy{};

    std::cout << "dummy.integrate(2, 4) = " << dummy.integrate(2, 4) << std::endl;
    return 0;
}