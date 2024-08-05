#include "PlayGame.h"

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
        else 
        {
            game.RunGame();
            UpdateMusicStream(game.musicOngame);
        }
    }
    CloseWindow();
    return 0;
}
