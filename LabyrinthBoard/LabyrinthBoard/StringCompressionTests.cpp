#include "StringCompressionTests.h"

#include "StringCompression.h"
#include <string>

void StringCompressionTests::PerformTests()
{
	this->TestRLE();
	this->TestMultipleRLE();
}

void StringCompressionTests::TestRLE()
{
	std::cout << "1)RLE" << std::endl;
	std::string empty("");
	auto emptyResult = StringCompression::RLE(empty);

	//it returns \0 escaped string
	if (emptyResult.size() == 1)
	{
		std::cout << "OK) Empty string pass.";
	}
	else
	{
		std::cout << "ERROR: Empty string fails.";
	}
	std::cout << std::endl;


	std::string nonRepetitive("ABCDEFG");
	auto result = StringCompression::RLE(nonRepetitive);

	if (result.compare(nonRepetitive) == 0)
	{
		std::cout << "OK) Non-repetitive pass.";
	}
	else
	{
		std::cout << "ERROR: Non-repetitive fails.";
	}
	std::cout << std::endl;


	std::string repetitive("XAAABBBBCDA");
	auto repetitiveResult = StringCompression::RLE(repetitive);

	if (repetitiveResult.compare("X3A4BCDA") == 0)
	{
		std::cout << "OK) Repetitive pass.";
	}
	else
	{
		std::cout << "ERROR: Repetitive fails.";
	}
	std::cout << std::endl;
}

void StringCompressionTests::TestMultipleRLE()
{
	std::cout << "2)Multiple RLE" << std::endl;

	std::string empty("");
	auto emptyResult = StringCompression::MultipleRLE(empty);

	//it returns \0 escaped string
	if (emptyResult.size() == 1)
	{
		std::cout << "OK) Empty string pass.";
	}
	else
	{
		std::cout << "ERROR: Empty string fails.";
	}
	std::cout << std::endl;


	std::string nonRepetitive("ABCDEFG");
	auto result = StringCompression::MultipleRLE(nonRepetitive);

	if (result.compare(nonRepetitive) == 0)
	{
		std::cout << "OK) Non-repetitive pass.";
	}
	else
	{
		std::cout << "ERROR: Non-repetitive fails.";
	}
	std::cout << std::endl;


	std::string repetitive("XAAABBBBCDA");
	auto repetitiveResult = StringCompression::MultipleRLE(repetitive);

	if (repetitiveResult.compare("X3A4BCDA") == 0)
	{
		std::cout << "OK) Repetitive pass.";
	}
	else
	{
		std::cout << "ERROR: Repetitive fails.";
	}
	std::cout << std::endl;


	std::string oneGroup("DDLDDLDDLK");
	auto oneGroupResult = StringCompression::MultipleRLE(oneGroup);

	if (oneGroupResult.compare("3(2DL)K") == 0)
	{
		std::cout << "OK) One group pass.";
	}
	else
	{
		std::cout << "ERROR: One group fails.";
	}
	std::cout << std::endl;


	std::string twoGroups("PDDLDDLDDLKMAALAAL");
	auto twoGroupsResult = StringCompression::MultipleRLE(twoGroups);

	if (twoGroupsResult.compare("P3(2DL)KM2(2AL)") == 0)
	{
		std::cout << "OK) Two groups pass.";
	}
	else
	{
		std::cout << "ERROR: Two groups fails.";
	}
	std::cout << std::endl;

	std::string nestedGroup("LRLRBLRLRB");
	auto nestedGroupResult = StringCompression::MultipleRLE(nestedGroup);

	if (nestedGroupResult.compare("2(2(LR)B)") == 0)
	{
		std::cout << "OK) Nested group pass.";
	}
	else
	{
		std::cout << "ERROR: Nested group fails.";
	}
	std::cout << std::endl;
}
