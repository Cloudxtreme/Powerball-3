
#pragma once

#include <string>
#include "Powerball.h"

using namespace std;




class Transducer
{
public:
	string transduce(string command);
private:
	Powerball powerball;

};