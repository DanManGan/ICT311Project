
#include "QuestionList.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

//--------------------------------------------------------------------------------------

QuestionList::QuestionList()
{
	Question();
}

//--------------------------------------------------------------------------------------

bool QuestionList::FileExists(string file)
{
	
// function to test entered file name is correct
	bool ok = false;

	ifstream infile(file);  // open input stream for defined file
		
// if input file is open and not corrupt return true
	if(infile.is_open())
		ok= true;	
	else
		cout << "Unable to open file question file \n";

	return ok;
}

//--------------------------------------------------------------------------------------

bool QuestionList::LoadQuestions(string file)
{
	// Load questions from formatted text file
// method variables
	bool ok = false;
	int answer = 0, key = 1; 
	string temp = "";
	string inputFile = "";
	
// check input file exists
	if(FileExists(file))
	{
		ok = true;
		deque<string> lines;
		Question question; // temporary transaction object to load data

		ifstream infile(file); // open input stream

// if input file is open read input stream & load to question object
		while(infile.good() && ok)
		{
			getline(infile, temp, ';');
			lines.push_back(temp);
			getline(infile, temp, ';');
			lines.push_back(temp);
			getline(infile, temp, ';');
			lines.push_back(temp);
			getline(infile, temp, ';');
			lines.push_back(temp);
			getline(infile, temp, ';');
			lines.push_back(temp);

			getline(infile, temp, '\n');
			answer = strInt(temp);

			question.SetQuestion(lines);
			question.SetAnswer(answer);

			m_questions.insert(make_pair(key, question)); // inser object with key
			lines.clear();
			question.Clear();
			key++;
		}

		infile.close();  // close stream when finished
	}

	return ok;
}

//--------------------------------------------------------------------------------------

std::map<int, Question> QuestionList::GetQuestions()
{
	return m_questions;
}

//--------------------------------------------------------------------------------------

void QuestionList::Clear()
{
	m_questions.clear();
}

//--------------------------------------------------------------------------------------

int QuestionList::strInt(string str)
{
// function to convert string to number
	stringstream ss;
	int temp;

	ss << str;
	ss >> temp;

	return temp;
}

//-----------------------------------------------------------------------------------------

float QuestionList::strFloat(string str)
{
// function to convert string to float
	stringstream ss;
	float temp;

	ss << str;
	ss >> temp;

	return temp;
}