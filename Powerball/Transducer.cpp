#include "Transducer.h"
#include <vector>
#include "misc.h"
using namespace std;


//ADD This is a string.

string Transducer::transduce(string command)
{
	string result;
	vector<string> token = tokenize(command);
	if((token[0]=="HELP")||(token[0]=="H"))
	{
		result="Commands:\n";
		result+="-------------------\n";
		result += "\tENTER NUMBERS (EN)\n";
		result += "\tCALCULATE FREQUENT NUMBERS (FN)\n";
		result += "\tGENERATE RANDOM NUMBERS (GN)\n";
		result += "\tGENERATE RANDOM NUMBERS WITH SEED (SR)\n";
		result+="\tHELP(H)\n";
		result += "\tDETAILED HELP (DH)\n";
		result+="\tQUIT(Q)\n";
	}
	else if ((token[0] == "ENTER NUMBERS") || (token[0] == "EN") || (token[0] =="en"))
	{
		result = powerball.enterNumbers(token[1]);
	}
	else if ((token[0] == "FN") || (token[0] == "fn"))
	{
		result = powerball.frequentNumbers();
	}
	else if ((token[0] == "GN") || (token[0] == "gn"))
	{
		result = powerball.generateRandomNumbers();
	}
	else if ((token[0] == "SR") || (token[0] == "sr"))
	{
		result = "need functionality 4";
	}
	else if ((token[0] == "DETAILED HELP") || (token[0] == "DH") || (token[0]=="dh"))
	{
		result = "need functionality";
	}
	else if((token[0]=="QUIT")||(token[0]=="Q")||(token[0]=="q"))
	{
		result="Goodbye.";
	}
	else
	{
		result="Unrecognized Command!!!";
	}
	return result;
}
