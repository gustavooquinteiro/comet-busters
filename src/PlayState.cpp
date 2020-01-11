#include "../include/PlayState.h"

const string PlayState::playID = "PLAY";

bool PlayState::onEnter()
{
    cout << "Entering play state" << endl;
    return true;
}

bool PlayState::onExit()
{
    cout << "Exiting play state" << endl;
    return true;
}

void PlayState::render()
{
}

void PlayState::update()
{
}

string PlayState::getStateID() const{ return this->playID; }


