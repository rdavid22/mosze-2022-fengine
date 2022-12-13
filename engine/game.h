#ifndef FENGINE_GAME_H_
#define FENGINE_GAME_H_

#include <iostream>
#include "objects/frame.h"
#include "objects/player.h"
#include "filehandler.h"
#include "console.h"

class Game
{
private:
    std::vector<Frame> all_frames_;
    std::vector<Player> all_players_;
    bool StartGame = false;
    bool ExitGame = false;
public:
    void LoadPlayers()
    {

    }

    void LoadFrames()
    {

    }

    void LoadMenu()
    {
        while(!StartGame)
        {
            
        }
    }

    void Start()
    {
        while(!ExitGame)
        {

        }
    }

};

#endif