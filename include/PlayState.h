#ifndef _PLAY_STATE_H_
#define _PLAY_STATE_H_

#include "GameState.h"

class PlayState: public GameState
{
public:
    void update() override;
    void render() override;
    
    bool onEnter() override;
    bool onExit() override;
    
    string getStateID() const override;
private:
    static const string playID;
};

#endif
