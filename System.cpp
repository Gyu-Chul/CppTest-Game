#include "System.h"
#include <iostream>

System::System() {}



void System::clear() {
    std::cout << "Clear the stage!" << std::endl;
}

void System::playerSelect() {
    std::cout << "Which Stage do you want?" << std::endl;
}

void System::fail() {
    std::cout << "Fail the stage!" << std::endl;
}

