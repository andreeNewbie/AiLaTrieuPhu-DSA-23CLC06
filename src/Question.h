#pragma once
#include<vector>
#include "C:\raylib\raylib\src\raylib.h"
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>
#include <iostream>

using namespace std;

class Question
{
    public:
        struct Option
        {
            char question[100];
            char A[30];
            char B[30];
            char C[30];
            char D[30];
            char correctAnswer[30];
        };
        Question();
        Option RandomDrawbyRequireLevel(int level);
    private:
        vector<vector<Option>> QuestionBank;
};