#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "GameObject.h"

class Player: public GameObject
{
public:
    long int getScore();
private:
    long int score;
};

#endif
