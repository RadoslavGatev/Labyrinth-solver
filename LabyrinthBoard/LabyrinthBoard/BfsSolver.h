#ifndef BFS_SOLVER_H
#define BFS_SOLVER_H

#include <queue>

#include "Solver.h"


class BfsSolver : public Solver
{
private:
	virtual std::vector<char> Solve_Internal(Board& board, Cell* pStart);
	void AddIfPassableAndNotVisited(std::queue<std::tuple<char, Cell*>> & cellQueue, Cell* pCell, char direction);
};


#endif // BFS_SOLVER_H