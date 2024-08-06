#include "Question.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>

Question::Question() // Read file and store to QuestionBank
{
    QuestionBank.resize(10); // Chỉnh sửa kích thước của QuestionBank để phù hợp với 10 mức độ khó
    for (int index = 0; index < 10; index++) {
        string questionFileName = "resources\\questions\\question" + to_string(index + 1) + ".csv";
        ifstream inputQuestion(questionFileName);
        if (!inputQuestion.is_open()) {
            cerr << "Unable to open file: " << questionFileName << endl;
            continue; // Tiếp tục với file tiếp theo nếu không mở được file hiện tại
        }
        string line;
        while (getline(inputQuestion, line)) {
            Option question;
            stringstream ss(line);
            string item;
            getline(ss, item, ';');
            strncpy(question.question, item.c_str(), sizeof(question.question) - 1);
            question.question[sizeof(question.question) - 1] = '\0';
            getline(ss, item, ';');
            strncpy(question.A, item.c_str(), sizeof(question.A) - 1);
            question.A[sizeof(question.A) - 1] = '\0';
            getline(ss, item, ';');
            strncpy(question.B, item.c_str(), sizeof(question.B) - 1);
            question.B[sizeof(question.B) - 1] = '\0';
            getline(ss, item, ';');
            strncpy(question.C, item.c_str(), sizeof(question.C) - 1);
            question.C[sizeof(question.C) - 1] = '\0';
            getline(ss, item, ';');
            strncpy(question.D, item.c_str(), sizeof(question.D) - 1);
            question.D[sizeof(question.D) - 1] = '\0';
            getline(ss, item, ';');
            strncpy(question.correctAnswer, item.c_str(), sizeof(question.correctAnswer) - 1);
            question.correctAnswer[sizeof(question.correctAnswer) - 1] = '\0';
            QuestionBank[index].push_back(question);
        }
        inputQuestion.close();
    }
}

Question::Option Question::RandomDrawbyRequireLevel(int level)
{
    if (level < 1 || level > 10) {
        throw out_of_range("Invalid level");
    }
    srand(static_cast<unsigned int>(time(0)));
    int index = rand() % QuestionBank[level - 1].size();
    return QuestionBank[level - 1][index];
}

