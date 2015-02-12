#ifndef BFS_SOLVER_H
#define BFS_SOLVER_H

#include <queue>

#include "Solver.h"
#include "CellTraverseInfo.h"


class BfsSolver : public Solver
{
private:
	virtual std::vector<char> Solve_Internal(Board& board, Cell* pStart);
	void AddIfPassableAndNotVisited(std::queue<CellTraverseInfo>& cellQueue, Cell* pCell, char direction, Cell* pSource);
};


#endif // BFS_SOLVER_H