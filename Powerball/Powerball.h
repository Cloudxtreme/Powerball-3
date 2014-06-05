#pragma once
#include "winningNumbers.h"
#include <vector>
#include <string>

using namespace std;


class Powerball
{
public:
	Powerball();
	string enterNumbers(string);
	string frequentNumbers();
	string generateRandomNumbers();
	string seedRandomNumbers(string);
private:
	int numberOfEntries;
	string formatNumbers(int, int, int, int, int, int);
	vector<WinningNumbers> vWinningNumbers;
	vector<string> tokenizeInput(string s);

};