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
            char question[200];
            char A[50];
            char B[50];
            char C[50];
            char D[50];
            char correctAnswer[50];
        };
        Question();
        Option RandomDrawbyRequireLevel(int level);
        void Sort();
        vector<Option> Search(int Level);
    private:
        vector<Option> QuestionBank;
};