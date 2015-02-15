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
	toCompress = RLE(toCompress);

	std::ostringstream oss;
	for (int substringCount = toCompress.size() / 2; substringCount >= 3; substringCount--)
	{
		int compressedTo = 0;
		for (size_t offset = 0; offset + 2 * substringCount < toCompress.size() &&
			compressedTo <= offset; offset++)
		{
			std::string::size_type nextfound = 0;
			std::string substr = toCompress.substr(offset, substringCount);
			nextfound = toCompress.find(substr, offset + substringCount);

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

					int next = offset + substringCount* occurences;
					if (toCompress.size() - next >= substringCount)
					{
						nextfound = toCompress.find(substr, next);
					}
					else
					{
						break;
					}
				}
			}

			if (occurences > 1)
			{

				std::string before(toCompress.substr(compressedTo, compressedTo - offset));

				oss << occurences;
				oss << "(" << substr << ")";

				compressedTo = offset + occurences*substringCount;
			}
		}

		if (compressedTo != 0)
		{
			std::string rest(toCompress.substr(compressedTo));
			oss << rest;
			toCompress = oss.str();
		}

		oss.str(std::string());
	}

	return toCompress;
}
