#include "../include/InputHandler.h"
#include "../include/Game.h"
#include <iostream>
using namespace std;

InputHandler* InputHandler::instance = 0;

InputHandler::InputHandler()
{
    keyState = SDL_GetKeyboardState(0);
    mousePosition = new Vector2D();
    for (long unsigned int i = 1; i < sizeof(mouse_buttons); i++)
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
            case SDL_MOUSEMOTION:
                mousePosition->setX(event.motion.x);
                mousePosition->setY(event.motion.y);
                break;
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

void InputHandler::reset()
{
    for (long unsigned int i = 0; i < sizeof(mouse_buttons) - 1; i++)
        mouseButtonStates[i] = false;
}

