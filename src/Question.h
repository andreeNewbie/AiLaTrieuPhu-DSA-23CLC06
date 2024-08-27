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
            char question[500];
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
        void QuickSort(int low, int high);
        int Partition(int low, int high);
        //void Swap(int i, int j);
};