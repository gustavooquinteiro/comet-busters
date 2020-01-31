#ifndef _COLLISION_
#define _COLLISION_
#include <SDL2/SDL.h>

const static buffer = 4;

static bool RectRect(SDL_Rect* A, SDL_Rect* B)
{
    int aHbuf = A->h / buffer;
    int aWbuf = A->w / buffer;
    
    int bHbuf = B->h / buffer;
    int bWbuf = B->w / buffer;
    
    if ((A->y + A->h) - aHbuf <= B->y + bHbuf) return false;
    if (A->y + aHbuf >= (B->h + B->y) - bHbuf) return false;
    if ((A->x + A->w) - aWbuf <= B->x + bWbuf) return false;
    if (A->x + aWbuf >= (B->x + B->w) - bWbuf) return false;
    
    return true;
}
#endif
