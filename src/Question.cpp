#include "Question.h"

Question::Question()//Read file and store to QuestionBank
{

}

Question::Option Question::RandomDrawbyRequireLevel(int level)
{
    //Generate Question Random

    Question::Option res;
    string a = "Ngo Hong Thanh co bi ngu khong ?";
    strcpy(res.question, a.c_str());
    string ans = "A. Co";
    strcpy(res.A, ans.c_str());
    strcpy(res.B, ans.c_str());
    strcpy(res.C, ans.c_str());
    strcpy(res.D, ans.c_str());
    strcpy(res.correctAnswer, ans.c_str());

    return res;
}