
#include "Question.h"

using namespace std;

//--------------------------------------------------------------------------------------

Question::Question()
{
	m_answer = -1;

	m_question.push_back("not set");
}

//--------------------------------------------------------------------------------------

void Question::SetQuestion(deque<string> &strings)
{
	m_question.clear();
	m_question = strings;
}

//--------------------------------------------------------------------------------------

void Question::SetAnswer(int answer)
{
	m_answer = answer;
}

//--------------------------------------------------------------------------------------

deque<string> Question::GetQuestion()
{
	return m_question;
}

//--------------------------------------------------------------------------------------

int Question::GetAnswer()
{
	return m_answer;
}

//--------------------------------------------------------------------------------------

void Question::Clear()
{
	m_answer = -1;

	m_question.clear();
}