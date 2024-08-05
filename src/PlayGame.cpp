#include "PlayGame.h"


PlayGame::PlayGame()
{
    background.loadInfo("resources/graphics/background.png", {-221.25, -450}, 0.6);
    logo.loadInfo("resources/graphics/logo.png", {278.7778, 50}, 0.7858);
    startButton.loadInfo("resources/graphics/start-button-login.png", {549.45, 580}, 0.3);
    exitButton.loadInfo("resources/graphics/exit-button.png", {1295, 0}, 0.25);

    game_background1.loadInfo("resources/graphics/background-gradient.png", {0, 0}, 0.7);
    game_background2.loadInfo("resources/graphics/background-game.png", {0, 0}, 0.83);
    money.loadInfo("resources/graphics/money-tree.png", {1120, 550}, 0.3);

    help_phoneFriend.loadInfo("resources/graphics/lifeline-phone-a-friend.png", {1120, 630}, 0.482);
    help_5050.loadInfo("resources/graphics/lifeline-50.png", {1120, 720}, 0.482);
    help_askAudience.loadInfo("resources/graphics/lifeline-ask-the-audience.png", {1120, 810}, 0.482);

    help_phoneFriend_used.loadInfo("resources/graphics/lifeline-phone-a-friend-orange.png", {1120, 630}, 0.482);
    help_5050_used.loadInfo("resources/graphics/lifeline-50-orange.png", {1120, 720}, 0.482);
    help_askAudience_used.loadInfo("resources/graphics/lifeline-ask-the-audience-orange.png", {1120, 810}, 0.482);

    font = LoadFontEx("resources/fonts/OpenSans-Bold.ttf", 64, 0, 0);

    A.loadInfo("resources/graphics/last-question.png", {10, 720}, 0.25);
    B.loadInfo("resources/graphics/last-question.png", {525, 720}, 0.25);
    C.loadInfo("resources/graphics/last-question.png", {10, 800}, 0.25);
    D.loadInfo("resources/graphics/last-question.png", {525, 800}, 0.25);

    A_wrong.loadInfo("resources/graphics/incorrect-answer.png", {-40, 722}, 0.4);
    B_wrong.loadInfo("resources/graphics/incorrect-answer.png", {470, 723}, 0.4);
    C_wrong.loadInfo("resources/graphics/incorrect-answer.png", {-40, 800}, 0.4);
    D_wrong.loadInfo("resources/graphics/incorrect-answer.png", {470, 802}, 0.4);

    A_right.loadInfo("resources/graphics/correct-answer.png", {-40, 722}, 0.4);
    B_right.loadInfo("resources/graphics/correct-answer.png", {480, 722}, 0.4);
    C_right.loadInfo("resources/graphics/correct-answer.png", {-40, 800}, 0.4);
    D_right.loadInfo("resources/graphics/correct-answer.png", {480, 800}, 0.4);

    ScreenQuestion.loadInfo("resources/graphics/last-question.png", {10, 583}, 0.51);

    gameStarted = false;
    correct = 1;
    exit = false;
    check = false;

    printA = printB = printC = printD = true;
    pressA = pressB = pressC = pressD = false;
    phoneFriend_used = help5050_used = askAudience_used = false;

    question = Question();
    countQuestionCorrected = 0;
    ques = question.RandomDrawbyRequireLevel(countQuestionCorrected + 1);

    InitAudioDevice();
    musicStart = LoadMusicStream("resources/sounds/StartGame.mp3");
    musicOngame = LoadMusicStream("resources/sounds/music01.mp3");
    correctAns = LoadSound("resources/sounds/correctAnswer1.mp3");
    correctTarget = LoadSound("resources/sounds/correctAnswer2.mp3");
    incorrect = LoadSound("resources/sounds/incorrectAnswer.mp3");
    newQuestion = LoadSound("resources/sounds/newQuestion.mp3");
    selectAnswer = LoadSound("resources/sounds/selectAnswer.mp3");
    win = LoadSound("resources/sounds/Winning.mp3");
}

void PlayGame::StartGame()
{
    PlayMusicStream(musicStart);
    BeginDrawing();
    ClearBackground(BLACK);
    background.Draw();
    logo.Draw();
    startButton.Draw();
    exitButton.Draw();
    EndDrawing();
    
    Vector2 mousePosition = GetMousePosition();
    bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

    if (startButton.isPress(mousePosition, mousePressed))
        gameStarted = true;
    if(exitButton.isPress(mousePosition, mousePressed))
        exit = true;

}


void PlayGame::Display()
{
    PlayMusicStream(musicOngame);
    ClearBackground(BLACK);
    game_background1.Draw();
    game_background2.Draw();

    ScreenQuestion.Draw();
    if (countQuestionCorrected != 0)
        money.Draw();

    DrawTextEx(font, "10. $1 MILLION", {1120, 10}, 38, 2, WHITE);

    if (countQuestionCorrected == 9)
        DrawTextEx(font, " 9. $500.000", {1120, 70}, 38, 2, BLACK);
    else DrawTextEx(font, " 9. $500.000", {1120, 70}, 38, 2, ORANGE);

    if (countQuestionCorrected == 8)
        DrawTextEx(font, " 8. $300.000", {1120, 130}, 38, 2, BLACK);
    else DrawTextEx(font, " 8. $300.000", {1120, 130}, 38, 2, ORANGE);

    DrawTextEx(font, " 7. $100.000", {1120, 190}, 38, 2, WHITE);

    if (countQuestionCorrected == 6)
        DrawTextEx(font, " 6. $50.000", {1120, 250}, 38, 2, BLACK);
    else DrawTextEx(font, " 6. $50.000", {1120, 250}, 38, 2, ORANGE);

    if (countQuestionCorrected == 5)
        DrawTextEx(font, " 5. $30.000", {1120, 310}, 38, 2, BLACK);
    DrawTextEx(font, " 5. $30.000", {1120, 310}, 38, 2, ORANGE);
    
    DrawTextEx(font, " 4. $10.000", {1120, 370}, 38, 2, WHITE);

    if (countQuestionCorrected == 3)
        DrawTextEx(font, " 3. $5.000", {1120, 430}, 38, 2, BLACK);
    else DrawTextEx(font, " 3. $5.000", {1120, 430}, 38, 2, ORANGE);

    if (countQuestionCorrected == 2)
        DrawTextEx(font, " 2. $1.000", {1120, 490}, 38, 2, BLACK);
    else DrawTextEx(font, " 2. $1.000", {1120, 490}, 38, 2, ORANGE);

    if (countQuestionCorrected == 1)
        DrawTextEx(font, " 1. $500", {1120, 550}, 38, 2, BLACK);
    else DrawTextEx(font, " 1. $500", {1120, 550}, 38, 2, ORANGE);

    DrawTextEx(font, ques.question, {100, 632}, 35, 2, WHITE);
}

void PlayGame::Handle()
{
    if (pressA)
    {
        if (correct != 2)
            A_wrong.Draw();
        else
            A_right.Draw();
    }
    else
    {
        if (correct == 3 && strcmp(ques.A, ques.correctAnswer) == 0)
            A_right.Draw();
        else
            A.Draw();
    }

    if (pressB)
    {
        if (correct != 2)
            B_wrong.Draw();
        else
            B_right.Draw();
    }
    else
    {
        if (correct == 3 && strcmp(ques.B, ques.correctAnswer) == 0)
            B_right.Draw();
        else
            B.Draw();
    }

    if (pressC) 
    {
        if (correct != 2)
            C_wrong.Draw();
        else
            C_right.Draw();
    }
    else
    {
        if (correct == 3 && strcmp(ques.C, ques.correctAnswer) == 0)
            C_right.Draw();
        else
            C.Draw();
    }

    if (pressD) 
    {
        if (correct != 2)
            D_wrong.Draw();
        else
            D_right.Draw();
    }
    else
    {
        if (correct == 3 && strcmp(ques.D, ques.correctAnswer) == 0)
            D_right.Draw();
        else
            D.Draw();
    }


    if(printA)
        DrawTextEx(font,ques.A, {75, 733}, 35, 2, WHITE);
    if(printB)
        DrawTextEx(font,ques.B, {580, 733}, 35, 2, WHITE);
    if(printC)
        DrawTextEx(font,ques.C, {75, 815}, 35, 2, WHITE);
    if(printD)
        DrawTextEx(font,ques.D, {580, 815}, 35, 2, WHITE);

    if (!phoneFriend_used)
        help_phoneFriend.Draw();
    else 
        help_phoneFriend_used.Draw();
    if (!help5050_used)
        help_5050.Draw();
    else
        help_5050_used.Draw();
    if (!askAudience_used)
        help_askAudience.Draw();
    else    
        help_askAudience_used.Draw();
}

void PlayGame::CheckAnswer()
{
    correct = 3;
    if (pressA && strcmp(ques.A, ques.correctAnswer) == 0)
    {
        correct = 2;
        countQuestionCorrected++;
    }
    if (pressB && strcmp(ques.B, ques.correctAnswer) == 0)
    {
        correct = 2;
        countQuestionCorrected++;
    }
    if (pressC && strcmp(ques.C, ques.correctAnswer) == 0)
    {
        correct = 2;
        countQuestionCorrected++;
    }
    if (pressD && strcmp(ques.D, ques.correctAnswer) == 0)
    {
        correct = 2;
        countQuestionCorrected++;
    }

    if (correct == 3)
        PlaySound(incorrect);
    if (correct == 2)
    {
        if (countQuestionCorrected == 4 || countQuestionCorrected == 7)
            PlaySound(correctTarget);
        if (countQuestionCorrected == 10)
            PlaySound(win);
        else
            PlaySound(correctAns);
    }

}

void waitAndExecute(int k) {
    this_thread::sleep_for(chrono::seconds(k));
}

void PlayGame::RunGame()
{
    if (correct == 2)
        money.loadInfo("resources/graphics/money-tree.png", {1120, 550 - float(60 * countQuestionCorrected - 60)}, 0.3);
    BeginDrawing();
    Display();
    Handle();
    EndDrawing();
    
    if (correct == 2)
    {
        waitAndExecute(3);
        ques = question.RandomDrawbyRequireLevel(countQuestionCorrected + 1);
        correct = 1;
        pressA = pressB = pressC = pressD = false;
    }
    if (correct == 3)
    {
        waitAndExecute(7);
        gameStarted = false;
        correct = 1;
        exit = false;
        check = false;

        printA = printB = printC = printD = true;
        pressA = pressB = pressC = pressD = false;
        phoneFriend_used = help5050_used = askAudience_used = false;

        countQuestionCorrected = 0;
        ques = question.RandomDrawbyRequireLevel(countQuestionCorrected + 1);
    }

    if ((pressA || pressB || pressC || pressD) && !check)
    {
        waitAndExecute(3);
        CheckAnswer();
        check = true;
    }

    Vector2 mousePosition = GetMousePosition();
    bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    if (A.isPress(mousePosition, mousePressed))
    {
        check = false;
        PlaySound(selectAnswer);
        pressA = true;
    }
    if (B.isPress(mousePosition, mousePressed))
    {
        check = false;
        PlaySound(selectAnswer);
        pressB = true;
    }
    if (C.isPress(mousePosition, mousePressed))
    {
        check = false;
        PlaySound(selectAnswer);
        pressC = true;
    }
    if (D.isPress(mousePosition, mousePressed))
    {
        check = false;
        PlaySound(selectAnswer);
        pressD = true;
    }
}