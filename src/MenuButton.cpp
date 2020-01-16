#include "../include/MenuButton.h"

MenuButton::MenuButton(void (*callback)()): callback(callback) {}

void MenuButton::update()
{
    //TODO: update function following SDL book on page 115
}

void MenuButton::clean()
{
    SDLGameObject::clean();
}

void MenuButton::draw()
{
    SDLGameObject::draw();
}

void MenuButton::load(const LoaderParams* params)
{
    SDLGameObject::load(params);
}
