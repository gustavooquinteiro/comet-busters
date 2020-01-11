#include "../include/InputHandler.h"
#include "../include/Game.h"
#include <iostream>
using namespace std;

InputHandler* InputHandler::instance = 0;

InputHandler::InputHandler()
{
    keyState = SDL_GetKeyboardState(0);
}
InputHandler::~InputHandler(){}

InputHandler* InputHandler::Instance()
{
    if (instance == 0)
        instance = new InputHandler();
    return instance;
}

void InputHandler::update()
{
    
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_KEYUP:
                onKeyUp();
                break;
            case SDL_KEYDOWN:
                onKeyDown();
                break;
            case SDL_QUIT:
                Game::Instance()->quit();
                break;
            default:
                break;
                
        }
    }
}

void InputHandler::onKeyDown()
{
}

void InputHandler::onKeyUp()
{
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
    if (keyState != 0)
        return keyState[key];
    return false;
}

