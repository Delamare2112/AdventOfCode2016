#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <unordered_map>
#include "../Common.hh"

void strDirectionsToVector(const std::string& input, std::vector<std::pair<char, int>>& output)
{
	for(std::string& s : TrevCommon::Split(input, ','))
    {
        s = TrevCommon::Trim(s);
        output.push_back(std::pair<char, int>(s[0], std::stoi(s.substr(1))));
    }
}

std::pair<int, int> GetOverlap(std::pair<int, int> pos, std::pair<int, int>& pos2, std::unordered_map<int, std::unordered_map<int, bool>>& map)
{
	while(pos != pos2)
	{
		if(pos.first == pos2.first)
			pos.second += pos.second < pos2.second ? 1 : -1;
		else
			pos.first += pos.first < pos2.first ? 1 : -1;
		bool& mark = map[pos.first][pos.second];
		if(mark)
			return pos;
		else
			mark = true;
	}
	return std::pair<int, int>(0,0);
}

static const std::pair<int, int> NoPair(0,0);
std::pair<int, int> GetFirstOverlap(std::vector<std::pair<char, int>>& directions)
{
	char currentDirection = 'N';
	std::pair<int, int> ret;
	std::unordered_map<int, std::unordered_map<int, bool>> map;
	for(std::pair<char, int>& pair : directions)
	{
		bool turningRight = pair.first == 'R';
		std::pair<int, int> oldPair = ret;
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
		std::pair<int, int> overlap = GetOverlap(oldPair, ret, map);
		if(overlap != NoPair)
			return overlap;
	}
	return NoPair;
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
	std::pair<int, int> lastPos(GetFirstOverlap(data));
	std::cout << "X: " << lastPos.first << ", Y: " << lastPos.second << '\n';
    std::cout << "Distance: " << abs(lastPos.first) + abs(lastPos.second) << '\n';
	return 0;
}
