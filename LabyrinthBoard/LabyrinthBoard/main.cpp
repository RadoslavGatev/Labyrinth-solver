#include <iostream>
#include <stack>
#include <string>

#include "Board.h"
#include "BfsSolver.h"
#include "StringCompression.h"


int main(int argc, char* argv[])
{
	// Will store the path to the file to open
	char path[_MAX_PATH];

	int fileCounter = 1;
	if (argc < 2)
	{
		std::cout << "Enter path to labyrinth file: ";
		std::cin.getline(path, _MAX_PATH);
	}
	// If the path is supplied as a command line argument, read it
	for (size_t i = 0; i < fileCounter; i++)
	{
		if (argc >= 2)
		{
			fileCounter = argc - 1;
			strcpy_s(path, _MAX_PATH, argv[1 + i]);
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
			std::vector<char> path = pSolver->Solve(board);

			std::cout << std::endl;
			for (size_t i = 0; i < path.size(); i++)
			{
				std::cout << path.at(i);
			}

			std::string strPath(path.begin(), path.end());

			std::cout << std::endl << StringCompression::RLE(strPath);

			// Do not forget to delete the solver object!
			delete pSolver;
		}
		else
		{
			std::cout << "failed!\n\n";
			std::cerr << "Cannot load labyrinth from input file!\n";
			return 1;
		}

		std::cout << "\n\n";
	}
	return 0;
}
