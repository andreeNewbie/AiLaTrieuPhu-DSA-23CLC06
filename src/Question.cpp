#include "Question.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>

Question::Question()//Read file and store to QuestionBank
{
    QuestionBank.resize(11);
    for(int index = 0; index < 10; index++) {
        QuestionBank[index].resize(6);
        string questionFileName = "D:\\2023-2024\\HK3\\DSA\\Project\\AiLaTrieuPhu-DSA-23CLC06\\resources\\questions\\question" + to_string(index + 1) + ".csv";
        ifstream inputQuestion(questionFileName);
        if (!inputQuestion.is_open()) {
            cerr << "Unable to open file: " << questionFileName << endl;
            return;
        }
        string line;
        while(getline(inputQuestion, line)) {
            Option *question = new Option;
            stringstream ss(line);
            string item;
            getline(ss, item, ';');
            strncpy(question->question, item.c_str(), sizeof(question->question));
            getline(ss, item, ';');
            strncpy(question->A, item.c_str(), sizeof(question->A));
            getline(ss, item, ';');
            strncpy(question->B, item.c_str(), sizeof(question->B));
            getline(ss, item, ';');
            strncpy(question->C, item.c_str(), sizeof(question->C));
            getline(ss, item, ';');
            strncpy(question->D, item.c_str(), sizeof(question->D));
            getline(ss, item, ';');
            strncpy(question->correctAnswer, item.c_str(), sizeof(question->correctAnswer));
            QuestionBank[index].push_back(question);
        }
        inputQuestion.close();
    }
    
}

Question::Option* Question::RandomDrawbyRequireLevel(int level)
{
    //Generate Question Random

    srand(time(0));
    int index = rand() % QuestionBank[level - 1].size();

    return QuestionBank[level - 1][index];

}