#include<iostream>
#include<vector>
using namespace std;

vector<string> split(string input, string delim)
{
	long long pos = 0;
	
	vector<string> ret;

	string token = "";
	
	while ( pos = input.find("delim") != std::string::npos)
	{
		string token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delim.length());
	}

	ret.push_back(input);
	return ret;

}


int main()
{

}