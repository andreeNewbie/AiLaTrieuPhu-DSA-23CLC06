#include "Question.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <string>
#include <cstdlib>

 Question::Question(){
    ifstream fin("resources\\questions\\question.csv");
    string line;

    if (!fin.is_open()) {
        cerr << "Can't open the file!\n";
        return;
    }

    while (getline(fin, line)){
        stringstream ss(line);
        string temp;
        Option opt;

        getline(ss, temp, ';');
        opt.level = stoi(temp);

        getline(ss, temp, ';');
        strncpy(opt.question, temp.c_str(), sizeof(opt.question) - 1);
        opt.question[sizeof(opt.question) - 1] = '\0';  

        getline(ss, temp, ';');
        strncpy(opt.A, temp.c_str(), sizeof(opt.A) - 1);
        opt.A[sizeof(opt.A) - 1] = '\0';  

        getline(ss, temp, ';');
        strncpy(opt.B, temp.c_str(), sizeof(opt.B) - 1);
        opt.B[sizeof(opt.B) - 1] = '\0'; 

        getline(ss, temp, ';');
        strncpy(opt.C, temp.c_str(), sizeof(opt.C) - 1);
        opt.C[sizeof(opt.C) - 1] = '\0';  

        getline(ss, temp, ';');
        strncpy(opt.D, temp.c_str(), sizeof(opt.D) - 1);
        opt.D[sizeof(opt.D) - 1] = '\0';  

        getline(ss, temp, ';');
        strncpy(opt.correctAnswer, temp.c_str(), sizeof(opt.correctAnswer) - 1);
        opt.correctAnswer[sizeof(opt.correctAnswer) - 1] = '\0'; 

        QuestionBank.push_back(opt);
    }

    fin.close();
}


// Question::Option Question::RandomDrawbyRequireLevel(int level)
// {
//     // if (level < 1 || level > 10) {
//     //     throw out_of_range("Invalid level");
//     // }
//     // srand(static_cast<unsigned int>(time(0)));
//     // int index = rand() % QuestionBank[level - 1].size();
//     // return QuestionBank[level - 1][index];
// }
Question::Option Question::RandomDrawbyRequireLevel(int level)
{
    vector<Option> filteredQuestions;

    for (const auto& question : QuestionBank){
        if (question.level == level)
            filteredQuestions.push_back(question);
    }

    if (filteredQuestions.empty()){
        cerr << "Error\n";
        exit(1);
    }

    srand(static_cast<unsigned int>(time(nullptr)));
    int randomIndex = rand() % filteredQuestions.size();

    return filteredQuestions[randomIndex];
}

// void Question::Swap(int i, int j){
//     Option temp = QuestionBank[i];
//     QuestionBank[i] = QuestionBank[j];
//     QuestionBank[j] = temp;
// }

int Question::Partition(int low, int high){
    int pivot = QuestionBank[high].level;
    int i = low - 1;

    for (int j = low; j < high; j++){
        if (QuestionBank[j].level <= pivot){
            i++;
            swap(QuestionBank[i],QuestionBank[j]);
        }
    }

    swap(QuestionBank[i + 1], QuestionBank[high]);
    return i+1;
}


void Question::QuickSort(int low, int high){
    if (low < high){
        int pivot = Partition(low, high);
        QuickSort(low, pivot - 1);
        QuickSort(pivot + 1, high);
    }
}

void Question::Sort()
{
    if (QuestionBank.empty()){
        QuickSort(0,QuestionBank.size()-1);
    }

}

vector<Question::Option> Question::Search(int level)
{
    vector<Option> results;

    for (auto& question : QuestionBank){
        if (question.level == level){
            results.push_back(question);
        }
    }
    return results;
}