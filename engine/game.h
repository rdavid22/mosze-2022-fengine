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
    Player current_player_;
    std::vector<Frame> all_frames_;
    std::vector<Player> all_players_;
    bool StartGame = false;
    bool ExitGame = false;

public:
    void LoadPlayers()
    {
        all_players_ = ReadPlayers();
    }

    void LoadFrames()
    {
        all_frames_ = ReadFrames();
    }

    void LoadMenu()
    {
        while (!StartGame)
        {
        }
    }

    void Start()
    {
        while (!ExitGame)
        {
        }
    }

    Frame GetFrameById(uint16_t id_to_get)
    {
        for(auto frame : all_frames_)
        {
            if(id_to_get == frame.GetId())
            {
                return frame;
            }
        }
    }
};

#endif