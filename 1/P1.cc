#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include "../Common.hh"

void strDirectionsToVector(const std::string& input, std::vector<std::pair<char, int>>& output)
{
	for(std::string& s : TrevCommon::Split(input, ','))
    {
        s = TrevCommon::Trim(s);
        output.push_back(std::pair<char, int>(s[0], std::stoi(s.substr(1))));
    }
}

std::pair<int, int> GetLastPosition(std::vector<std::pair<char, int>>& directions)
{
	char currentDirection = 'N';
	std::pair<int, int> ret;
	for(std::pair<char, int>& pair : directions)
	{
		bool turningRight = pair.first == 'R';
		switch(currentDirection)
		{
		case 'N':
			ret.first += turningRight ? pair.second : -pair.second;
			currentDirection = turningRight ? 'E' : 'W'; break;
		case 'E':
			ret.second += turningRight ? -pair.second : pair.second;
			currentDirection = turningRight ? 'S' : 'N'; break;
		case 'S':
			ret.first += turningRight ? -pair.second : pair.second;
			currentDirection = turningRight ? 'W' : 'E'; break;
		case 'W':
			ret.second += turningRight ? pair.second : -pair.second;
			currentDirection = turningRight ? 'N' : 'S'; break;
		}
	}
	return ret;
}

std::string GetInput(int& n, char const* args[])
{
	if(n < 2)
	{
		std::cout << "Yo, where that input?\n";
		exit(1);
	}
	return std::string(TrevCommon::GetWholeFile(args[1]));
}

int main(int argc, char const *argv[])
{
	std::vector<std::pair<char, int>> data;
	strDirectionsToVector(GetInput(argc, argv), data);
	std::pair<int, int> lastPos(GetLastPosition(data));
	std::cout << "X: " << lastPos.first << ", Y: " << lastPos.second << '\n';
    std::cout << "Distance: " << abs(lastPos.first) + abs(lastPos.second) << '\n';
	return 0;
}
