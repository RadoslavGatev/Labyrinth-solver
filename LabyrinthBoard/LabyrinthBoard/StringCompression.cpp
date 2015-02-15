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

	if (rest.length() > 1)
	{
		oss << rest.length();
	}
	oss << toCompress[found];
	return oss.str();
}

std::string StringCompression::MultipleRLE(std::string toCompress)
{
	std::string result = RLE(toCompress);

	std::ostringstream oss;
	for (int substringCount = result.size() / 2; substringCount >= 3; substringCount--)
	{
		int compressedTo = 0;
		int lastCompressedTo = 0;
		for (size_t offset = 0; offset + 2 * substringCount - 1 < result.size(); offset++)
		{
			std::string::size_type nextfound = 0;
			std::string substr = result.substr(offset, substringCount);
			nextfound = result.find(substr, offset + substringCount);

			int occurences = 1;
			while (nextfound != std::string::npos)
			{
				if (nextfound != offset + substringCount*occurences)
				{
					break;
				}
				else
				{
					occurences++;
					compressedTo = nextfound;

					int next = offset + substringCount* occurences;
					if (result.size() - next >= substringCount)
					{
						nextfound = result.find(substr, next);
					}
					else
					{
						break;
					}
				}
			}

			if (occurences > 1)
			{
				std::string before(result.substr(lastCompressedTo, offset - lastCompressedTo));

				oss << before << occurences;
				oss << "(" << substr << ")";

				compressedTo = offset + occurences*substringCount;
				lastCompressedTo = compressedTo;
				offset = compressedTo - 1;
			}
		}

		if (compressedTo != 0)
		{
			std::string rest(result.substr(compressedTo));
			oss << rest;
			result = oss.str();
		}

		oss.str(std::string());
	}

	return result;
}
