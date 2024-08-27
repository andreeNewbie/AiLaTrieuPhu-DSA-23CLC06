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
#include <algorithm>

using namespace std;

class Question
{
    public:
        struct Option
        {
            int level;
            char question[100];
            char A[30];
            char B[30];
            char C[30];
            char D[30];
            char correctAnswer[30];
        };
        Question();
        Option RandomDrawbyRequireLevel(int level);
        void Sort();
        vector<Option> Search(int Level);
    private:
        vector<Option> QuestionBank;
        void QuickSort(int low, int high);
        int Partition(int low, int high);
};