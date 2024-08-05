#include "Question.h"

Question::Question() // Read file and store to QuestionBank
{
<<<<<<< Updated upstream

=======
    srand(time(0)); // Initialize random seed once
    QuestionBank.resize(11);
    for (int index = 0; index < 10; index++) {
        QuestionBank[index].resize(6);
        string questionFileName = "resources/questions/question" + to_string(index + 1) + ".csv";
        ifstream inputQuestion(questionFileName);
        if (!inputQuestion.is_open()) {
            cerr << "Unable to open file: " << questionFileName << endl;
            return;
        }
        string line;
        while (getline(inputQuestion, line)) {
            Option* question = new Option;
            stringstream ss(line);
            string item;
            getline(ss, item, ';');
            strncpy(question->question, item.c_str(), sizeof(question->question) - 1);
            question->question[sizeof(question->question) - 1] = '\0';
            getline(ss, item, ';');
            strncpy(question->A, item.c_str(), sizeof(question->A) - 1);
            question->A[sizeof(question->A) - 1] = '\0';
            getline(ss, item, ';');
            strncpy(question->B, item.c_str(), sizeof(question->B) - 1);
            question->B[sizeof(question->B) - 1] = '\0';
            getline(ss, item, ';');
            strncpy(question->C, item.c_str(), sizeof(question->C) - 1);
            question->C[sizeof(question->C) - 1] = '\0';
            getline(ss, item, ';');
            strncpy(question->D, item.c_str(), sizeof(question->D) - 1);
            question->D[sizeof(question->D) - 1] = '\0';
            getline(ss, item, ';');
            strncpy(question->correctAnswer, item.c_str(), sizeof(question->correctAnswer) - 1);
            question->correctAnswer[sizeof(question->correctAnswer) - 1] = '\0';
            QuestionBank[index].push_back(question);
        }
        inputQuestion.close();
    }
>>>>>>> Stashed changes
}

Question::Option Question::RandomDrawbyRequireLevel(int level)
{
    if (level < 1 || level > QuestionBank.size()) {
        cerr << "Invalid level: " << level << endl;
        return nullptr;
    }

    if (QuestionBank[level - 1].empty()) {
        cerr << "No questions available for level: " << level << endl;
        return nullptr;
    }

<<<<<<< Updated upstream
    Question::Option res1, res2;
    string a = "Ngo Hong Thanh co bi ngu khong ?";
    string b = "Nhut Anh co bi ngu khong?";
    strcpy(res1.question, a.c_str());
    strcpy(res2.question, b.c_str());
    string ans = "A. Co";
    string test = "B. Khong";
    strcpy(res1.A, test.c_str());
    strcpy(res1.B, ans.c_str());
    strcpy(res1.C, ans.c_str());
    strcpy(res1.D, ans.c_str());
    strcpy(res1.correctAnswer, test.c_str());

    strcpy(res2.A, test.c_str());
    strcpy(res2.B, test.c_str());
    strcpy(res2.C, ans.c_str());
    strcpy(res2.D, ans.c_str());
    strcpy(res2.correctAnswer, ans.c_str());

    return level == 1 ? res1 : res2;
}
=======
    int index = rand() % QuestionBank[level - 1].size();
    return QuestionBank[level - 1][index];
}
>>>>>>> Stashed changes
