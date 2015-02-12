#include <iostream>
#include <stack>

#include "BfsSolver.h"
#include "Point.h"
#include "DirectionsUtility.h"

/**
 *
 *	Uses Breadth-first search to check if there is a path
 *	between pStart and the target cell in the board.
 *
 */
std::vector<char> BfsSolver::Solve_Internal(Board & board, Cell * pStart, char target)
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

	//start solving
	std::queue<CellTraverseInfo> cellQueue;

	CellTraverseInfo info(NULL, pStart, ' ');
	cellQueue.push(info);

	CellTraverseInfo pCurrent;

	while (!cellQueue.empty())
	{
		// Get the next element from the stack
		pCurrent = cellQueue.front();
		pCurrent.destination->MarkVisited();

		cellQueue.pop();

		//store it in path
		if (pCurrent.source != NULL)
		{
			path[pCurrent.destination->GetRow()][pCurrent.destination->GetCol()] =
				Point(pCurrent.source->GetRow(), pCurrent.source->GetCol(), pCurrent.direction);
		}

		// Display some information
		std::cout << "\n   Queue size: " << cellQueue.size();
		std::cout << "\n   Popped ";
		pCurrent.destination->PrintInfo();
		std::cout << std::endl;

		if (pCurrent.destination->GetSymbol() == target)
		{
			// If the target is found, then there is a path
			break;
		}
		else
		{
			// Otherwise keep looking
			AddIfPassableAndNotVisited(cellQueue, pCurrent.destination->GetLeftNeighbour(), 'L', pCurrent.destination);
			AddIfPassableAndNotVisited(cellQueue, pCurrent.destination->GetRightNeighbour(), 'R', pCurrent.destination);
			AddIfPassableAndNotVisited(cellQueue, pCurrent.destination->GetTopNeighbour(), 'U', pCurrent.destination);
			AddIfPassableAndNotVisited(cellQueue, pCurrent.destination->GetBottomNeighbour(), 'D', pCurrent.destination);
		}
	}

	//add path
	std::stack<Point> currentPath;
	if (pCurrent.destination->GetSymbol() == target)
	{

		Point currentPoint = path[pCurrent.destination->GetRow()][pCurrent.destination->GetCol()];

		do
		{
			currentPath.push(currentPoint);

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
		Point current = currentPath.top();

		Cell* currentCell = board.GetCell(current.row, current.col);
		if (currentCell->IsKey())
		{
			board.GetDefinitions().MarkAsCollected(currentCell->GetSymbol());
		}
		else if (currentCell->IsDoor())
		{
			if (!board.GetDefinitions().IsCollected(currentCell->GetSymbol()))
			{
				CellInfo* keyInfo = board.GetDefinitions().FindKeyForADoor(currentCell->GetSymbol());
				if (keyInfo != NULL)
				{
					board.MarkAllCellsNotVisited();
					board.GetDefinitions().MarkAsCollected(keyInfo->caption);
					std::vector<char> pathToKey = Solve_Internal(board, currentCell, keyInfo->caption);

					//path to key
					results.insert(results.end(), pathToKey.begin(), pathToKey.end());

					//path back to the door
					for (int i = pathToKey.size() - 1; i >= 0; i--)
					{
						results.push_back(DirectionsUtility::GetReverse(pathToKey.at(i)));
					}

					//results.push_back(current.direction);
				}
			}
		}

		results.push_back(current.direction);

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
void BfsSolver::AddIfPassableAndNotVisited(std::queue<CellTraverseInfo> &cellQueue, Cell* pCell, char direction, Cell* pSource)
{
	std::cout << "      Should we add ";
	pCell->PrintInfo();
	std::cout << "? ...";

	if (pCell && (pCell->IsPassable() || pCell->IsDoor() || pCell->IsKey()) && !pCell->IsVisited())
	{
		std::cout << "Yes";

		// Mark the cell as visited
		pCell->MarkVisited();

		// Enqeue the cell
		cellQueue.push(CellTraverseInfo(pSource, pCell, direction));
	}
	else
	{
		std::cout << "No";
	}

	std::cout << std::endl;
}