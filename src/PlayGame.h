#pragma once
#include "C:\\raylib\\raylib\\src\\raylib.h"
#include "Button.hpp"
#include "Background.hpp"
#include "Question.h"

using namespace std;

class PlayGame
{
    public:
        PlayGame();
        void StartGame();
        void RunGame();
        void upDate();
        bool gameStarted;
    private:
        Background background;
        Background logo;
        Button startButton;

        Background game_background1;
        Background game_background2;
        
        Background help_phoneFriend;
        Background help_5050;
        Background help_askAudience;
        
        Font font;

        Button A;
        Button B;
        Button C;
        Button D;
        Background ScreenQuestion;
        Question question;
        Question::Option ques;
};