#include "Powerball.h"
#include "misc.h"
#include <algorithm>
#include <iostream>
#include <time.h>

using namespace std;

Powerball::Powerball()
{
	numberOfEntries = 0;
}

string Powerball::enterNumbers(string ln)
{
	WinningNumbers nWN;
	vector<string> vNums = tokenizeInput(ln);
	nWN.date = vNums[0];

	for (int i = 1; i < 8; i++)
	{
		nWN.vSingleWinNums.push_back(stringToInt(vNums[2*i]));
	}

	nWN.isDeleted = false;
	numberOfEntries++;
	nWN.id = numberOfEntries;

	vWinningNumbers.push_back(nWN);

	return "Numbers Added: " + ln;
}

string Powerball::frequentNumbers()
{
	int w1=0, w2=0, w3=0, w4=0, w5=0, pb=0, divisor=0;
	int temp = 0, index = 0;
	int freqArray[6][60] = { 0 };
	string result;

	vector<WinningNumbers>::iterator iter;
	iter = vWinningNumbers.begin();

	while (iter != vWinningNumbers.end())
	{
		w1 = (*iter).vSingleWinNums[0];
		w2 = (*iter).vSingleWinNums[1];
		w3 = (*iter).vSingleWinNums[2];
		w4 = (*iter).vSingleWinNums[3];
		w5 = (*iter).vSingleWinNums[4];
		pb = (*iter).vSingleWinNums[5];

		freqArray[0][w1] = freqArray[0][w1]++;
		freqArray[1][w2] = freqArray[1][w2]++;
		freqArray[2][w3] = freqArray[2][w3]++;
		freqArray[3][w4] = freqArray[3][w4]++;
		freqArray[4][w5] = freqArray[4][w5]++;
		freqArray[5][pb] = freqArray[5][pb]++;	
		iter++;
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			if (temp < freqArray[i][j])
			{
				temp = freqArray[i][j];
				index = j;
			}
		}
		switch (i)
		{
		case 0:
			w1 = index;
			break;
		case 1:
			w2 = index;
			break;
		case 2:
			w3 = index;
			break;
		case 3:
			w4 = index;
			break;
		case 4:
			w4 = index;
			break;
		case 5:
			pb = index;
			break;
		default:
			cout << "put an error handler here!" << endl;
		}
		temp = 0;
	}
	

	result = formatNumbers(w1, w2, w3, w4, w5, pb);

	return result;
}

string Powerball::generateRandomNumbers()
{
	string result; 
	int w1, w2, w3, w4, w5, pb;

	w1 = (rand() % 59) + 1;
	w2 = (rand() % 59) + 1;
	w3 = (rand() % 59) + 1;
	w4 = (rand() % 59) + 1;
	w5 = (rand() % 59) + 1;
	pb = (rand() % 59) + 1;

	result = formatNumbers(w1, w2, w3, w4, w5, pb);


	return result;
}

string Powerball::formatNumbers(int w1,int w2,int w3,int w4,int w5,int pb)
{
	string result; 

	result += intToString(w1) + " ";
	result += intToString(w2) + " ";
	result += intToString(w3) + " ";
	result += intToString(w4) + " ";
	result += intToString(w5) + " ";
	result += "PB: " + intToString(pb) + "\n";

	return result; 
}

vector<string> Powerball::tokenizeInput(string s)
{
	vector<string> result;
	string temp;

	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			result.push_back(temp);
			temp = "";
		}
		else
		{
			temp += s[i];
		}
	}
	result.push_back(temp);

	return result;
}