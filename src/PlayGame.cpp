#include "PlayGame.h"


PlayGame::PlayGame()
{
    background.loadInfo("resources/graphics/background.png", {-221.25, -450}, 0.6);
    logo.loadInfo("resources/graphics/logo.png", {278.7778, 50}, 0.7858);
    startButton.loadInfo("resources/graphics/start-button-login.png", {549.45, 580}, 0.3);
    
    game_background1.loadInfo("resources/graphics/background-gradient.png", {0, 0}, 0.7);
    game_background2.loadInfo("resources/graphics/background-game.png", {0, 0}, 0.83);

    help_phoneFriend.loadInfo("resources/graphics/lifeline-phone-a-friend.png", {1120, 630}, 0.482);
    help_5050.loadInfo("resources/graphics/lifeline-50.png", {1120, 720}, 0.482);
    help_askAudience.loadInfo("resources/graphics/lifeline-ask-the-audience.png", {1120, 810}, 0.482);

    font = LoadFontEx("resources/fonts/OpenSans-Bold.ttf", 64, 0, 0);

    A.loadInfo("resources/graphics/last-question.png", {10, 720}, 0.25);
    B.loadInfo("resources/graphics/last-question.png", {520, 720}, 0.25);
    C.loadInfo("resources/graphics/last-question.png", {10, 800}, 0.25);
    D.loadInfo("resources/graphics/last-question.png", {520, 800}, 0.25);
    ScreenQuestion.loadInfo("resources/graphics/last-question.png", {10, 583}, 0.51);

    gameStarted = false;
    question = Question();
    ques = question.RandomDrawbyRequireLevel(1);
}

void PlayGame::StartGame(){

    BeginDrawing();
    ClearBackground(BLACK);
    background.Draw();
    logo.Draw();
    startButton.Draw();
    EndDrawing();
    
    Vector2 mousePosition = GetMousePosition();
    bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

    if (startButton.isPress(mousePosition, mousePressed))
        gameStarted = true;

}

void PlayGame::RunGame()
{
    BeginDrawing();
    ClearBackground(BLACK);
    game_background1.Draw();
    game_background2.Draw();
    A.Draw();
    B.Draw();
    C.Draw();
    D.Draw();
    ScreenQuestion.Draw();
    DrawTextEx(font, "10. $1 MILLION", {1120, 10}, 38, 2, WHITE);
    DrawTextEx(font, "10. $1 MILLION", {1120, 10}, 38, 2, WHITE);
    DrawTextEx(font, " 9. $500.000", {1120, 70}, 38, 2, ORANGE);
    DrawTextEx(font, " 8. $300.000", {1120, 130}, 38, 2, ORANGE);
    DrawTextEx(font, " 7. $100.000", {1120, 190}, 38, 2, WHITE);
    DrawTextEx(font, " 6. $50.000", {1120, 250}, 38, 2, ORANGE);
    DrawTextEx(font, " 5. $30.000", {1120, 310}, 38, 2, ORANGE);
    DrawTextEx(font, " 4. $10.000", {1120, 370}, 38, 2, WHITE);
    DrawTextEx(font, " 3. $5.000", {1120, 430}, 38, 2, ORANGE);
    DrawTextEx(font, " 2. $1.000", {1120, 490}, 38, 2, ORANGE);
    DrawTextEx(font, " 1. $500", {1120, 550}, 38, 2, ORANGE);
    help_phoneFriend.Draw();
    help_5050.Draw();
    help_askAudience.Draw();

    DrawTextEx(font, ques.question, {100, 632}, 35, 2, WHITE);

    EndDrawing();
}