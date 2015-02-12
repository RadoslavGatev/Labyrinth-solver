#include "CellDefinitions.h"

const char CellDefinitions::Wall = '#';
const char CellDefinitions::Start = 'S';
const char CellDefinitions::End = 'X';
const char CellDefinitions::Corridor = ' ';

CellInfo * CellDefinitions::FindKeyForADoor(char doorSymbol)
{
	if (this->doorsAndKeys.find(doorSymbol) == this->doorsAndKeys.end())
	{
		return NULL;
	}

	return &this->doorsAndKeys.find(doorSymbol)->second;
}

void CellDefinitions::AddDoorAndKey(char doorSymbol, CellInfo keyCell)
{
	this->doorsAndKeys.insert(std::pair<char, CellInfo>(doorSymbol, keyCell));
}
