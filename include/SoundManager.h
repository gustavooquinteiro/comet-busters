#ifndef _SOUND_MANAGER_H_
#define _SOUND_MANAGER_H_

#include <SDL2/SDL_mixer.h>
#include <map>
#include <string>
using namespace std;

enum sound_type
{
    SOUND_MUSIC,
    SOUND_SFX
};

class SoundManager
{
public:
    static SoundManager* Instance();
    bool load(string filename, string id, sound_type type);
    void playSound(string id, int loop);
    void playMusic(string id, int loop);
private:
    static SoundManager* instance;
    map<string, Mix_Chunk*> sfxs;
    map<string, Mix_Music*> musics;
    SoundManager();
    ~SoundManager();
    
    SoundManager(const SoundManager&);
    SoundManager& operator=(const SoundManager&);
};

#endif
