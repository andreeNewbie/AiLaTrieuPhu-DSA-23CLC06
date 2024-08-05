#include "Question.h"

Question::Question()//Read file and store to QuestionBank
{

}

Question::Option Question::RandomDrawbyRequireLevel(int level)
{
    //Generate Question Random

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