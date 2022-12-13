#ifndef FENGINE_MENU_H_
#define FENGINE_MENU_H_

#include "console.h"

class Menu
{

private:
    bool StartGame = false;

public:
    void PrintMainMenu()
    {
        console::printLine(BLUE, "\nMenu:");
        console::printLine(BLUE, "1 - jatekos betoltese");
        console::printLine(BLUE, "2 - jatekos letrehozasa");
        console::printLine(BLUE, "3 - jatekos torlese");
        console::printLine(BLUE, "0 - kilepes");
    }
};

#endif