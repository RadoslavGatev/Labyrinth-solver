#include <iostream>
#include <stack>
#include <string>

#include "Board.h"
#include "BfsSolver.h"
#include "StringCompression.h"

int main()
{
	std::string result = StringCompression::Compress("LLLRRRLRLRLLRR");
	std::cout << result;
}

int maink(int argc, char* argv[])
{
	// Will store the path to the file to open
	char path[_MAX_PATH];

	// If the path is supplied as a command line argument, read it
	if (argc == 2)
	{
		strcpy_s(path, _MAX_PATH, argv[1]);
	}
	else
	{
		std::cout << "Enter path to labyrinth file: ";
		std::cin.getline(path, _MAX_PATH);
	}

	// Create a board and try to load the contents of the file
	Board board;

	std::cout << "Trying to load labyrinth from \"" << path << "\"...";

	if (board.LoadFromFile(path))
	{
		std::cout << "done\n\n";

		// If loading was successful, print the board
		board.Print();

		if (board.GetRowsCount() == 0)
		{
			std::cout << "The board is empty.\n";
			return 0;
		}

		Solver* pSolver = NULL;

		pSolver = new BfsSolver();

		// Try to find the path
		std::vector<char> pathExists = pSolver->PathExists(board);

		std::cout << std::endl;
		for (size_t i = 0; i < pathExists.size(); i++)
		{
			std::cout << pathExists.at(i);
		}

		// Do not forget to delete the solver object!
		delete pSolver;

		/*	std::cout
				<< "\n   "
				<< (pathExists ? "There is a path!" : "Sorry, there is no path!")
				<< std::endl;*/
	}
	else
	{
		std::cout << "failed!\n\n";
		std::cerr << "Cannot load labyrinth from input file!\n";
		return 1;
	}

	return 0;
}
