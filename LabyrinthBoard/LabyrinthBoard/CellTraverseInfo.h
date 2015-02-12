#ifndef CELLTRAVERSEINFO_H
#define CELLTRAVERSEINFO_H

#include "Cell.h"

struct CellTraverseInfo {
	Cell* source;
	Cell* destination;
	char direction;

	CellTraverseInfo()
	{
		source = NULL;
		destination = NULL;
	}

	CellTraverseInfo(Cell* source, Cell* destination, char direction)
	{
		this->source = source;
		this->destination = destination;
		this->direction = direction;
	}
};

#endif