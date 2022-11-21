#include "../include/SoundManager.h"
#include <iostream>
#include <string>

SoundManager* SoundManager::instance = 0;

SoundManager* SoundManager::Instance()
{
    if (instance == 0)
        instance = new SoundManager();
    return instance;
}

SoundManager::SoundManager()
{
    Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
}

bool SoundManager::load(std::string filename, std::string id, sound_type type)
{
    if (type == SOUND_MUSIC)
    {
        Mix_Music* music = Mix_LoadMUS(filename.c_str());
        if (music == 0)
        {
            cerr << Mix_GetError() << endl;
            return false;
        }
        musics[id] = music;
        return true;
    }
    else if (type == SOUND_SFX)
    {
        Mix_Chunk* chunk =  Mix_LoadWAV(filename.c_str());
        if (chunk == 0)
        {
            cerr << Mix_GetError() << endl;
            return false;
        }
        sfxs[id] = chunk;
        return true;
    }
    return false;
}

void SoundManager::playMusic(std::string id, int loop)
{
    Mix_PlayMusic(musics[id], loop);
}

void SoundManager::playSound(std::string id, int loop)
{
    Mix_PlayChannel(-1, sfxs[id], loop);
}

SoundManager::~SoundManager()
{
    Mix_CloseAudio();
}

