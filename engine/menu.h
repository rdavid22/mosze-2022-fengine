#ifndef FENGINE_MENU_H_
#define FENGINE_MENU_H_

#include "console.h"
#include "objects/frame.h"
#include "objects/player.h"
#include "filehandler.h"

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
        while (!start_game_)
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
                start_game_ = true;
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
        // Init player object.
        Player new_player;

        // Get user input.
        console::printLine(BLUE, "Jatekos neve: (kilepes a 0 beirasaval)");
        std::string user_input = console::input();

        // Check if user wants to navigate back to the main menu.
        if (user_input == "0")
        {
            start_game_ = false;
            return;
        }

        // Check if name already exist.
        for (auto player : all_player_)
        {
            if (player.GetName() == user_input)
            {
                console::printLineAnim(RED, "A jatekos mar letezik!");
                CreatePlayerScreen();
                return;
            }
        }

        // If not, set the default name & scene number.
        new_player.SetName(user_input);
        new_player.SetFrameId(0);

        // Add player to global list.
        all_player_.push_back(new_player);

        // Choose the newly created player to the current player.
        current_player_ = new_player;

        // Save game state
        SavePlayer(current_player_);
    }

    void DeletePlayerScreen()
    {
        console::printLine(BLUE, "\nJatekos torlese: (kilepes a 0 beirasaval)");
        PrintAllPlayers();
        std::string user_input = console::input();

        // Check if user wants to navigate back to the main menu.
        if (user_input == "0")
        {
            start_game_ = false;
            return;
        }

        else
        {
            // Delete selected player from the savegame file.
            uint16_t index = stoi(user_input);
            if (index <= all_player_.size() && index >= 0)
            {
                all_player_.erase(all_player_.begin() + index);
                SavePlayer(current_player_);
            }
            // Invalid input
            else
            {
                console::printLineAnim(RED, "A kivalasztott jatekos nem letezik!");
            }
        }
        start_game_ = false;
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
        return current_player_;
    }

    std::vector<Player> GetAllPlayer()
    {
        return all_player_;
    }
};

#endif