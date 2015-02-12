#include <iostream>
#include <stack>

#include "BfsSolver.h"
#include "Point.h"


/**
 *
 *	Uses Breadth-first search to check if there is a path
 *	between pStart and the target cell in the board.
 *
 */
std::vector<char> BfsSolver::Solve_Internal(Board& board, Cell* pStart)
{
	std::cout << "Solving with BFS\n\n";

	Point** path = new Point*[board.GetRowsCount()];

	for (size_t i = 0; i < board.GetRowsCount(); i++)
	{
		path[i] = NULL;
	}

	for (size_t i = 0; i < board.GetRowsCount(); i++)
	{
		path[i] = new Point[board.GetColsCount()];
	}

	std::queue<std::tuple<char, Cell*>> cellQueue;

	cellQueue.push(std::make_tuple(' ', pStart));

	Cell* pCurrent = NULL;
	Cell* pPrevious = NULL;

	while (!cellQueue.empty())
	{
		// Get the next element from the stack
		pCurrent = std::get<1>(cellQueue.front());
		pCurrent->MarkVisited();

		char direction = std::get<0>(cellQueue.front());
		cellQueue.pop();

		//store it in path
		if (pPrevious != NULL)
		{
			path[pCurrent->GetRow()][pCurrent->GetCol()] = Point(pPrevious->GetRow(), pPrevious->GetCol(), direction);
		}

		// Display some information
		std::cout << "\n   Queue size: " << cellQueue.size();
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
			AddIfPassableAndNotVisited(cellQueue, pCurrent->GetLeftNeighbour(), 'L');
			AddIfPassableAndNotVisited(cellQueue, pCurrent->GetRightNeighbour(), 'R');
			AddIfPassableAndNotVisited(cellQueue, pCurrent->GetTopNeighbour(), 'U');
			AddIfPassableAndNotVisited(cellQueue, pCurrent->GetBottomNeighbour(), 'D');
		}

		pPrevious = pCurrent;
	}

	//add path
	std::stack<char> currentPath;
	if (pCurrent->IsTarget())
	{

		Point currentPoint = path[pCurrent->GetRow()][pCurrent->GetCol()];

		do
		{
			currentPath.push(currentPoint.direction);

			int previousRow = currentPoint.row;
			int previousCol = currentPoint.col;
			if (previousRow == -1 || previousCol == -1)
			{
				break;
			}

			currentPoint = path[previousRow][previousCol];
		} while (!currentPoint.IsNull());
	}

	for (size_t r = 0; r < board.GetRowsCount(); r++)
	{
		for (size_t c = 0; c < board.GetColsCount(); c++)
		{
			std::cout << path[r][c].direction;
		}
		std::cout << std::endl;
	}

	//delete
	for (size_t i = 0; i < board.GetRowsCount(); i++)
	{
		delete[] path[i];
	}

	delete[] path;

	//get results from the stack
	std::vector<char> results;

	while (!currentPath.empty())
	{
		results.push_back(currentPath.top());
		currentPath.pop();
	}

	return results;
}


/**
 *
 *	Adds a cell to the queue cellQueue, but only if it is passable
 *	and has not been visited until now.
 *	The function also marks the cell as visited.
 *
 */
void BfsSolver::AddIfPassableAndNotVisited(std::queue<std::tuple<char, Cell*>> & cellQueue, Cell* pCell, char direction)
{
	std::cout << "      Should we add ";
	pCell->PrintInfo();
	std::cout << "? ...";

	if (pCell && pCell->IsPassable() && !pCell->IsVisited())
	{
		std::cout << "Yes";

		// Mark the cell as visited
		pCell->MarkVisited();

		// Enqeue the cell
		cellQueue.push(std::make_tuple(direction, pCell));
	}
	else
	{
		std::cout << "No";
	}

	std::cout << std::endl;
}