#include "/Users/huynick/Documents/raylib/src/raylib.h"
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include "Button.hpp"
#include "Background.hpp"
#include "PlayGame.h"
using namespace std;

int main() 
{
    InitWindow(1357, 900, "WHO WANT TO BE A BILLIONAIRE");
    SetTargetFPS(60);

    PlayGame game = PlayGame();

    if (game.exit) {
        // If there was an initialization error, exit early
        std::cerr << "Game initialization failed. Exiting..." << std::endl;
        CloseWindow();
        return -1;
    }
    
    while(!WindowShouldClose() && !game.exit)
    {   
        if (game.gameStarted == false)
        {
            game.StartGame();
            UpdateMusicStream(game.musicStart);
        }
        else 
        {
            game.RunGame();
            UpdateMusicStream(game.musicOngame);
        }
    }

    CloseWindow();
    return 0;
}
