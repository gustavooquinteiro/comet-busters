#ifndef _SCREEN_HANDLER_H_
#define _SCREEN_HANDLER_H_

#include "Vector2D.h"
#include "Game.h"

static bool isOutOfWidth(Vector2D position)
{
    if (position.getX() > Game::Instance()->getGameWidth() || 
        position.getX() < 0)
        return true;
    return false;
}

static bool isOutOfHeight(Vector2D position)
{
    if (position.getY() > Game::Instance()->getGameHeight() || 
        position.getY() < 0)
        return true;
    return false;
}

static bool isInScreen(Vector2D position)
{
    if (!isOutOfWidth(position) && !isOutOfHeight(position))
        return true;
    return false;
}
#endif
