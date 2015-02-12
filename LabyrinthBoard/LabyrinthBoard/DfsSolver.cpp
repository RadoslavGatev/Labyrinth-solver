#include <iostream>
#include <stack>

#include <deque>
#include <tuple>
#include "DfsSolver.h"
#include "Point.h"


/**
 *
 *	Uses Depth-first search to check if there is a path
 *	between pStart and the target cell in the board.
 *
 */
std::vector<char> DfsSolver::Solve(Board& board, Cell* pStart)
{
	std::cout << "Solving with DFS\n\n";

	Point** path = new Point*[board.GetRowsCount()];

	for (size_t i = 0; i < board.GetRowsCount(); i++)
	{
		path[i] = new Point[board.GetColsCount];
	}

	std::stack<std::tuple<char, Cell*>> cellStack;

	cellStack.push(std::make_tuple(' ', pStart));

	Cell* pCurrent = NULL;
	Cell* pNeghbour = NULL;
	std::deque<char> path;

	while (!cellStack.empty())
	{
		// Get the next element from the stack
		pCurrent = std::get<1>(cellStack.top());

		pCurrent->MarkVisited();
		path.push_back(std::get<0>(cellStack.top()));
		cellStack.pop();

		// Display some information
		std::cout << "\n   Stack size: " << cellStack.size();
		std::cout << "\n   Popped ";
		pCurrent->PrintInfo();
		std::cout << std::endl;

		if (pCurrent->IsTarget())
		{
			// If the target is found, then there is a path
			break;
		}
		else
		{
			// Otherwise keep looking

			AddIfPassableAndNotVisited(cellStack, pCurrent->GetLeftNeighbour(), 'L');
			AddIfPassableAndNotVisited(cellStack, pCurrent->GetRightNeighbour(), 'R');
			AddIfPassableAndNotVisited(cellStack, pCurrent->GetTopNeighbour(), 'U');
			AddIfPassableAndNotVisited(cellStack, pCurrent->GetBottomNeighbour(), 'D');
		}
	}



	for (size_t i = 0; i < board.GetRowsCount(); i++)
	{
		delete[] path[i];
	}

	delete[] path;

	return (std::vector<char>)path;
}


/**
 *
 *	Adds a cell to the stack cellStack, but only if it is passable
 *	and has not been visited until now.
 *	The function also marks the cell as visited.
 *
 */
void DfsSolver::AddIfPassableAndNotVisited(std::stack<std::tuple<char, Cell*>> & cellStack, Cell* pCell, char direction)
{
	std::cout << "      Should we add ";
	pCell->PrintInfo();
	std::cout << "? ...";

	if (pCell && pCell->IsPassable() && !pCell->IsVisited())
	{
		std::cout << "Yes";

		// Mark the cell as visited
		pCell->MarkVisited();

		// Push the cell to the stack
		cellStack.push(pCell);
	}
	else
	{
		std::cout << "No";
	}

	std::cout << std::endl;
}