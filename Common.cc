#include "Common.hh"
#include <sstream>
#include <fstream>

namespace TrevCommon
{
	std::vector<std::string> Split(const std::string& str, char delim)
	{
		std::vector<std::string> ret;
		std::stringstream ss;
		ss.str(str);
		for(std::string i; std::getline(ss, i, delim); ret.push_back(i));
		return ret;
	}

	std::string GetWholeFile(const char*& path)
	{
		std::ifstream t(path);
		t.seekg(0, std::ios::end);
		size_t size = t.tellg();
		std::string buffer(size, ' ');
		t.seekg(0);
		t.read(&buffer[0], size);
		return buffer;
	}
}
