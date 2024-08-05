#pragma once
#include<vector>
#include "/Users/huynick/Documents/raylib/src/raylib.h"
#include <string>
#include <cstring>

using namespace std;

class Question
{
    public:
        struct Option
        {
            char question[200];
            char A[50];
            char B[50];
            char C[50];
            char D[50];
            char correctAnswer[50];
        };
        Question();
        Option RandomDrawbyRequireLevel(int level);
    private:
        vector<vector<Option*> > QuestionBank;
};