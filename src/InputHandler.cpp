#include "../include/InputHandler.h"

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
}

void InputHandler::clean()
{
}
