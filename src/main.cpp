#include "C:\\raylib\\raylib\\src\\raylib.h"
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
    InitWindow(1357.5, 900, "WHO WANT TO BE A BILLIONAIRE");
    SetTargetFPS(60);

    PlayGame game = PlayGame();
    
    while(!WindowShouldClose() && !game.exit)
    {   
        if (game.gameStarted == false)
        {
            game.StartGame();
            UpdateMusicStream(game.musicStart);
        }
        else if (game.correct)
        {
            game.RunGame();
            UpdateMusicStream(game.musicOngame);
        }
    }
    CloseWindow();
    return 0;
}
