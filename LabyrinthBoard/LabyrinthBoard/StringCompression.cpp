#include "StringCompression.h"

#include <sstream>

std::string StringCompression::RLE(std::string toCompress)
{
	std::string::size_type found = 0, nextfound = 0;
	std::ostringstream oss;
	nextfound = toCompress.find_first_not_of(toCompress[found], found);
	while (nextfound != std::string::npos)
	{
		int occurences = nextfound - found;
		if (occurences > 1)
		{
			oss << occurences;
		}
		oss << toCompress[found];
		found = nextfound;
		nextfound = toCompress.find_first_not_of(toCompress[found], found);
	}

	//since we must not discard the last characters we add them at the end of the string
	std::string rest(toCompress.substr(found));//last run of characters starts at position found 
	oss << rest.length() << toCompress[found];
	return oss.str();
}
