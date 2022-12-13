#ifndef FENGINE_MENU_H_
#define FENGINE_MENU_H_

#include "console.h"
#include "objects/frame.h"
#include "objects/player.h"

class Menu
{

private:
    Player current_player_;
    std::vector<Frame> all_frame_;
    std::vector<Player> all_player_;
    bool start_game_ = false;

public:
    Menu(std::vector<Frame> all_frame, std::vector<Player> all_player)
    {
        all_frame_ = all_frame;
        all_player_ = all_player;
    }

    void LoadMainMenu()
    {
        while (!StartGame)
        {
            PrintWelcomeScreen();
            GetMenuOption();
        }
    }

    void PrintWelcomeScreen()
    {
        console::printLine(BLUE, "\nMenu:");
        console::printLine(BLUE, "1 - jatekos betoltese");
        console::printLine(BLUE, "2 - jatekos letrehozasa");
        console::printLine(BLUE, "3 - jatekos torlese");
        console::printLine(BLUE, "0 - kilepes");
    }

    void GetMenuOption()
    {
        std::string option = console::input();
        if (option == "1")
        {
            LoadPlayerScreen();
        }
        else if (option == "2")
        {
            CreatePlayerScreen();
        }
        else if (option == "3")
        {
            DeletePlayerScreen();
        }
        else
        {
            console::printLineAnim(RED, "Nincs ilyen opcio!");
        }
    }

    void LoadPlayerScreen()
    {
        PrintAllPlayers();
        std::string selected_player = console::input();
        for (int i = 0; i < all_player_.size(); i++)
        {
            // Check if player exist
            if (selected_player == std::to_string(i + 1))
            {
                current_player_ = all_player_[i];
                return;
            }
            // Go back to main menu
            else if (selected_player == "0")
            {
                start_game_ = false;
                return;
            }
        }
        console::printLineAnim(RED, "A kivalasztott jatekos nem letezik!");
        LoadPlayerScreen();
    }

    void CreatePlayerScreen()
    {
    }

    void DeletePlayerScreen()
    {
        PrintAllPlayers();
    }

    void PrintAllPlayers()
    {
        console::printLineAnim(GREEN, "Osszes jatekos:");
        for (auto player : all_player_)
        {
            console::printLineAnim(BLUE, player.GetName());
        }
    }

    Player GetCurrentPlayer()
    {
    }
};

#endif