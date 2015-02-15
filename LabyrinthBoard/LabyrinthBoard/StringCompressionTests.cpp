#include "StringCompressionTests.h"

#include "StringCompression.h"
#include <string>

void StringCompressionTests::PerformTests()
{
	this->TestRLE();
}

void StringCompressionTests::TestRLE()
{
	std::string empty("");
	auto emptyResult = StringCompression::RLE(empty);

	//it returns \0 escaped string
	if (emptyResult.size() == 1)
	{
		std::cout << "OK) Empty string pass.";
	}
	else
	{
		std::cout << "ERROR: Empty string";
	}
	std::cout << std::endl;


	std::string nonSequentive("ABCDEFG");
	auto result = StringCompression::RLE(nonSequentive);

	if (result.compare(nonSequentive) == 0)
	{
		std::cout << "OK) Non-sequentive pass.";
	}
	else
	{
		std::cout << "ERROR: Non-sequentive";
	}
	std::cout << std::endl;


	std::string sequentive("XAAABBBBCDA");
	auto sequentiveResult = StringCompression::RLE(sequentive);

	if (sequentiveResult.compare("X3A4BCDA") == 0)
	{
		std::cout << "OK) Sequentive pass.";
	}
	else
	{
		std::cout << "ERROR: Sequentive";
	}
	std::cout << std::endl;
}
