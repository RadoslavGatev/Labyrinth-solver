#ifndef STRINGCOMPRESION_H
#define STRINGCOMPRESION_H

#include <iostream>

/**
*	Contains compression algorithms.
*/
class StringCompression
{
public:
	/**
	*	Run Length Encoding. Source from RosettaCode.
	*/
	static std::string RLE(std::string toCompress);

	static std::string MultipleRLE(std::string toCompress);
};

#endif