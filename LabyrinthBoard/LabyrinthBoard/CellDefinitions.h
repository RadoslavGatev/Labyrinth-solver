#ifndef CELLDEFINITIONS_H
#define CELLDEFINITIONS_H

#include <map>

#include "CellInfo.h"

class CellDefinitions {
public:
	static const char Wall;
	static const char Start;
	static const char End;
	static const char Corridor;

	CellInfo* FindKeyForADoor(char doorSymbol);
	void AddDoorAndKey(char doorSymbol, CellInfo keyCell);

private:
	std::map<char, CellInfo> doorsAndKeys;

};

#endif
