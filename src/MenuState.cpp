#include "../include/MenuState.h"
#include "../include/StateParser.h"
#include "../include/TextureManager.h"

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


string MainMenuState::getStateID() const{ return this->menuID; }

bool MainMenuState::onEnter()
{
    StateParser stateparser;
    stateparser.parseState("test.xml", menuID, &gameObjects, &textureIDList);
    callbacks.push_back(0);
    callbacks.push_back(menuToPlay);
    callbacks.push_back(exitFromMenu);
    
    setCallbacks(callbacks);
    return true;
}

void MainMenuState::setCallbacks(const vector<MenuState::Callback>& callbacks)
{
    for(auto gameObject: gameObjects)
    {
        if (dynamic_cast<MenuButton*>(gameObject))
        {
            MenuButton* button = dynamic_cast<MenuButton*>(gameObject);
            button->setCallback(callbacks[button->getCallbackID()]);
        }
    }
}

bool MainMenuState::onExit()
{
    for(auto textureIDs: textureIDList)
    {
        TextureManager::Instance()->clearFromTextureMap(textureIDs);
    }
}

