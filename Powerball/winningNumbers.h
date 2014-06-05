#pragma once
#include <string>
#include <vector>

using namespace std;

class WinningNumbers
{
public:
	friend class Powerball;
private:
	string date;
	vector <int> vSingleWinNums;
	int id; 
	bool isDeleted;
};
