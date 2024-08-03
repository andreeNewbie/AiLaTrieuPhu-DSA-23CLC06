#include "C:\\raylib\\raylib\\src\\raylib.h"
#include <iostream>
#include "Button.hpp"
#include "Background.hpp"

using namespace std;

void GameStarting() {
    Background game_background("graphics/game-background.png", {0, 0}, 0.56);
    Button A("graphics/last-question.png", {10, 720}, 0.25);
    Button B("graphics/last-question.png", {520, 720}, 0.25);
    Button C("graphics/last-question.png", {10, 800}, 0.25);
    Button D("graphics/last-question.png", {520, 800}, 0.25);
    Button Question("graphics/last-question.png", {10, 583}, 0.51);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        game_background.Draw();
        A.Draw();
        B.Draw();
        C.Draw();
        D.Draw();
        Question.Draw();
        EndDrawing();
    }
}

int main() {
    InitWindow(1237.5, 900, "WHO WANT TO BE A BILLIONAIRE");
    SetTargetFPS(60);

    Background background("graphics/background.png", {-281.25, -450}, 0.6);
    Background logo("graphics/logo.png", {218.75, 50}, 0.7858);
    Button startButton("graphics/start-button-login.png", {489.45, 580}, 0.3);

    bool gameStarted = false;

    while (!WindowShouldClose() && !gameStarted) {
        Vector2 mousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (startButton.isPress(mousePosition, mousePressed)) {
            gameStarted = true;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        background.Draw();
        logo.Draw();
        startButton.Draw();
        EndDrawing();
    }

    if (gameStarted) {
        GameStartxing();
    }

    CloseWindow();
    return 0;
}
