#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include "Cell.h"
#include "Board.h"


class Solver
{
public:
	virtual ~Solver();

public:
	std::vector<char> PathExists(Board& board);

protected:
	virtual std::vector<char> Solve_Internal(Board& board, Cell* pStart) = 0;
};


#endif // SOLVER_H