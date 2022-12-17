#include <iostream>
#include "game.h"
#include"helper.h"
int main()
{

    PlaySound();
    Game game;

    game.LoadPlayers();
    game.LoadFrames();
    game.LoadMenu();
    game.Start();
    
    return 0;
}