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

void CellDefinitions::MarkAsCollected(char doorSymbol, char key)
{
	CellInfo& cellInfo = this->doorsAndKeys.at(doorSymbol);
	if (cellInfo.caption == key)
	{
		cellInfo.isColected = true;
	}
}

bool CellDefinitions::IsCollected(char doorSymbol)
{
	CellInfo& cellInfo = this->doorsAndKeys.at(doorSymbol);
	return cellInfo.isColected;
}

void CellDefinitions::AddDoorAndKey(char doorSymbol, CellInfo keyCell)
{
	this->doorsAndKeys.insert(std::pair<char, CellInfo>(doorSymbol, keyCell));
}

void CellDefinitions::UpdateKeyLocation(char key, int row, int column)
{
	for (auto& kv : doorsAndKeys)
	{
		if (kv.second.caption == key)
		{
			kv.second.row = row;
			kv.second.col = column;
		}
	}
}

bool CellDefinitions::IsKey(char key)
{
	for (auto& kv : doorsAndKeys)
	{
		if (kv.second.caption == key)
		{
			return true;
		}
	}

	return false;
}

bool CellDefinitions::IsDoor(char door)
{
	return doorsAndKeys.find(door) != doorsAndKeys.end();
}
