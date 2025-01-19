#include "System.h"

System::System() {}

void System::clear() {
    cout << "Clear the stage!" << endl;
}

void System::playerSelect() {
    cout << "Which stage do you want?" << endl;
}

void System::fail() {
    cout << "Fail the stage!" << endl;
}
