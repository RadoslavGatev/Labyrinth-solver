#ifndef DFS_SOLVER_H
#define DFS_SOLVER_H

#include <stack>

#include <vector>
#include "Solver.h"


class DfsSolver : public Solver
{
private:
	virtual std::vector<char> Solve(Board& board, Cell* pStart);
	void AddIfPassableAndNotVisited(std::stack<std::tuple<char, Cell*>> & cellStack, Cell* pCell, char direction);
};


#endif // DFS_SOLVER_H