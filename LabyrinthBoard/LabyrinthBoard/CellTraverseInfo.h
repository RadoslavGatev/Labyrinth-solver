#ifndef CELLTRAVERSEINFO_H
#define CELLTRAVERSEINFO_H

#include "Cell.h"

/**
*	Stores information about the traverse - contains source cell and destination cell.
*/
struct CellTraverseInfo {
	/**
	*	The source Cell
	*/
	Cell* source;

	/**
	*	The destination cell.
	*/
	Cell* destination;

	/**
	*	The direction of the traverse. Stored according to the rules specified in \ref DirectionsUtility
	*/
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