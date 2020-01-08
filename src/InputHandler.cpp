#include "../include/InputHandler.h"
#include <iostream>
using namespace std;

InputHandler* InputHandler::instance = 0;

InputHandler::InputHandler(){}
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
                break;
            case SDL_KEYDOWN:
                break;
            case SDL_QUIT:
                break;
            default:
                break;
                
        }
    }
}

void InputHandler::clean()
{
}
