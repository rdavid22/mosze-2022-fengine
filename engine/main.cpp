#include <iostream>
#include "game.h"

int main()
{
    Game game;

    game.LoadPlayers();
    game.LoadFrames();
    game.LoadMenu();
    game.Start();
    
    return 0;
}