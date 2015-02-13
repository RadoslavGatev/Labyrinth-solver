#ifndef BFS_SOLVER_H
#define BFS_SOLVER_H

#include <queue>

#include "Solver.h"
#include "CellTraverseInfo.h"
#include "Point.h"

class BfsSolver : public Solver
{
private:
	virtual std::vector<char> Solve_Internal(Board& board, Cell* pStart, char target);
	void AddIfPassableAndNotVisited(std::queue<CellTraverseInfo>& cellQueue, Cell* pCell, char direction, Cell* pSource);
	void ExtractPath(Board& board, std::vector<char>& results, std::stack<Point>& pathStack);
};


#endif // BFS_SOLVER_H