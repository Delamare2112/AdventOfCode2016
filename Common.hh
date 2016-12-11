#include <string>
#include <vector>
#include <algorithm>

namespace TrevCommon
{
	std::vector<std::string> Split(const std::string& str, char delim);
	std::string GetWholeFile(const char*& path);
	inline std::string Trim(const std::string &s)
	{
		auto wsfront=std::find_if_not(s.begin(),s.end(),[](int c){return std::isspace(c);});
		return std::string(wsfront,std::find_if_not(s.rbegin(),std::string::const_reverse_iterator(wsfront),[](int c){return std::isspace(c);}).base());
	}
}
