#pragma once
#include "C:\\raylib\\raylib\\src\\raylib.h"
#include "Button.hpp"
#include "Background.hpp"
#include "Question.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

#include <chrono>
#include <thread>

using namespace std;

class PlayGame
{
    public:
        PlayGame(); 
        //~PlayGame();
        void StartGame();
        void RunGame();
        void Display();
        void CheckAnswer();
        void Handle();
        void waitAndExecute(int k);
        bool gameStarted;
        int correct; //1. Normal, 2. Correct, 3.Incorrect
        bool exit;
        bool check;
        Music musicStart;
        Music musicOngame;
        int countQuestionCorrected;
        void Apply5050Lifeline();
        void ApplyPhoneFriendLifeline();
    private:
        int handle;
        Sound correctAns, correctTarget, incorrect;
        Sound newQuestion, selectAnswer, win;
        Sound help_5050_sound, help_phoneFriend_sound, phone_ring;
        Background background;
        Background logo;
        Button startButton, exitButton;

        Background game_background1, game_background2, money;
        
        Button help_phoneFriend, help_5050, help_askAudience;
        Button help_phoneFriend_used, help_5050_used, help_askAudience_used;
        Button friendAns;
        Background phoneFriend_view;
        Font font;

        Button A, B, C, D;
        Button A_wrong, B_wrong, C_wrong, D_wrong;
        Button A_right, B_right, C_right, D_right;

        Background ScreenQuestion;
        Question question;
        Question::Option ques;

        bool printA, printB, printC, printD;
        bool pressA, pressB, pressC, pressD;
        bool showFriendAns;
        string finallyAnswer;
        bool phoneFriend_used, help5050_used, askAudience_used;
};