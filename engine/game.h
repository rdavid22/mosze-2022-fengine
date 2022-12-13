#ifndef FENGINE_GAME_H_
#define FENGINE_GAME_H_

#include <iostream>
#include "objects/frame.h"
#include "objects/player.h"
#include "filehandler.h"
#include "console.h"
#include "menu.h"

class Game
{
private:
    Player current_player_;
    Frame current_frame_;
    std::vector<Frame> all_frames_;
    std::vector<Player> all_players_;
    bool exit_game_ = false;

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
        Menu menu(all_frames_, all_players_);
        menu.LoadMainMenu();
        current_player_ = menu.GetCurrentPlayer();
        all_players_ = menu.GetAllPlayer();
    }

    void Start()
    {
        current_frame_ = GetFrameById(current_player_.GetFrameId());
        while (!exit_game_)
        {
            PrintFrame();
            std::string input = console::input();
            if(input == "exit"){return;}
            GoToFrame(std::stoi(input)); 
        }
    }

    void PrintFrame()
    {
        console::clear();
        console::printLineAnim(GREEN, current_frame_.GetText());
        uint16_t selector = 1;
        for (auto ans : current_frame_.GetAnswers())
        {
            console::printLineAnim(BLUE, selector + ": " + ans.GetText());
            selector++;
        }
    }
    bool GoToFrame(uint16_t selector)
    {
        auto ans = current_frame_.GetAnswers();
        if (selector > ans.size() || selector < 1)
        {
            return false;
        }

        current_frame_ = GetFrameById(ans[selector - 1].GetId());
        return true;
    }
    Frame GetFrameById(uint16_t id_to_get)
    {
        for (auto frame : all_frames_)
        {
            if (id_to_get == frame.GetId())
            {
                return frame;
            }
        }
        return Frame();
    }
};

#endif