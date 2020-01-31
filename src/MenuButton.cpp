#include "../include/MenuButton.h"
#include "../include/InputHandler.h"

MenuButton::MenuButton(){}

void MenuButton::update()
{
    Vector2D* mousePosition = InputHandler::Instance()->getMousePosition();
    if (mousePosition->getX() < (position.getX() + width) && mousePosition->getX() > position.getX() && 
        mousePosition->getY() < (position.getY() + height) && mousePosition->getY() > position.getY())
    {
        if (InputHandler::Instance()->getMouseButtonState(InputHandler::LEFT) && buttonReleased)
        {
            currentFrame = CLICKED;
            callback();
            buttonReleased = false;
        }
        else if (!InputHandler::Instance()->getMouseButtonState(InputHandler::LEFT))
        {
            buttonReleased = true;
            currentFrame = MOUSE_OVER; 
        }
        else
        {
            currentFrame = MOUSE_OUT;
        }  
    }   
}

void MenuButton::clean()
{
    GameObject::clean();
}

void MenuButton::draw()
{
    GameObject::draw();
}

void MenuButton::load(const LoaderParams* params)
{
    GameObject::load(params);
    callbackID = params->getCallbackID();    
    currentFrame = MOUSE_OUT;
}

void MenuButton::setCallback(void (*callback)()){ this->callback = callback; }

int MenuButton::getCallbackID(){ return this->callbackID; }
