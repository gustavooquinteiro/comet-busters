#include "../include/InputHandler.h"
#include "../include/Game.h"
#include <iostream>
using namespace std;

InputHandler* InputHandler::instance = 0;

InputHandler::InputHandler()
{
    keyState = SDL_GetKeyboardState(0);
    for (int i = 1; i < sizeof(mouse_buttons); i++)
        mouseButtonStates.push_back(false);        
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
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                    mouseButtonStates[LEFT] = true;
                
                if (event.button.button == SDL_BUTTON_MIDDLE)
                    mouseButtonStates[MIDDLE] = true;
                
                if (event.button.button == SDL_BUTTON_RIGHT)
                    mouseButtonStates[RIGHT] = true;
                break;
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT)
                    mouseButtonStates[LEFT] = false;
                
                if (event.button.button == SDL_BUTTON_MIDDLE)
                    mouseButtonStates[MIDDLE] = false;
                
                if (event.button.button == SDL_BUTTON_RIGHT)
                    mouseButtonStates[RIGHT] = false;
                break;
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

bool InputHandler::getMouseButtonState(int buttonNumber){ return mouseButtonStates[buttonNumber]; }

Vector2D * InputHandler::getMousePosition(){ return mousePosition; }


