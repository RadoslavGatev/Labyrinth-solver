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
	void MarkAsCollected(char key);
	bool IsCollected(char doorSymbol);
	void AddDoorAndKey(char doorSymbol, CellInfo keyCell);
	void UpdateKeyLocation(char key, int row, int column);
	bool IsKey(char key);
	bool IsDoor(char door);

private:
	std::map<char, CellInfo> doorsAndKeys;

};

#endif
