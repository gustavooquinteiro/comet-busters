#include "../include/MenuState.h"

const string MenuState::menuID = "MENU";

bool MenuState::onEnter()
{
    cout << "Entering menu state" << endl;
    return true;
}

bool MenuState::onExit()
{
    cout << "Exiting menu state" << endl;
    return true;
}

void MenuState::render()
{
}

void MenuState::update()
{
}

string MenuState::getStateID() const{ return this->menuID; }


