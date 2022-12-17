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
        Console.WriteLine("\nMenu:",BLUE);
        Console.WriteLine("1 - jatekos betoltese",BLUE);
        Console.WriteLine("2 - jatekos letrehozasa",BLUE);
        Console.WriteLine("3 - jatekos torlese" ,BLUE);
        Console.WriteLine("4 - jatekosok torlese",BLUE);
       // Console.WriteLine("5 - dani specialis kerese",BLUE);
    }

    void GetMenuOption()
    {
        std::string option = Console.ReadLine();
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
        else if (option == "4")
        {
            all_player_.clear();
            DeletePlayers();
        }
        else if (option == "5")
        {
            for (int i = 0; i < all_player_.size(); i++)
            {
                all_player_[i].SetFrameId(0);
            }
            ResetPlayers();
        }

        else
        {
           Console.WriteLine("Nincs ilyen opcio!",RED);
        }
    }

    void LoadPlayerScreen()
    {
        PrintAllPlayers();
        std::string selected_player = Console.ReadLine();
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
        Console.WriteLine( "A kivalasztott jatekos nem letezik!",RED);
        LoadPlayerScreen();
    }

    void CreatePlayerScreen()
    {
        // Init player object.
        Player new_player;

        // Get user input.
       Console.WriteLine("Jatekos neve: (kilepes a 0 beirasaval)",BLUE);
        std::string user_input = Console.ReadLine();

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
                Console.WriteLine("A jatekos mar letezik!",RED);
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
       Console.WriteLine("\nJatekos torlese: (kilepes a 0 beirasaval)",BLUE);
        PrintAllPlayers();
        std::string user_input = Console.ReadLine();

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
                all_player_.erase(all_player_.begin() + (index - 1));
                DeletePlayerByName(all_player_[(index - 1)].GetName());
            }
            // Invalid input
            else
            {
                Console.WriteLine("A kivalasztott jatekos nem letezik!",RED);
            }
        }
        start_game_ = false;
    }

    void PrintAllPlayers()
    {
        Console.WriteLine( "Osszes jatekos:",GREEN);
        for (auto player : all_player_)
        {
            Console.WriteLine(player.GetName(),BLUE);
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