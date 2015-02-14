#ifndef CELLDEFINITIONS_H
#define CELLDEFINITIONS_H

#include <map>

#include "KeyInfo.h"


/**
 *	This class contains the definitions of the remarkable cells like walls, corridors,
 *	start & end, keys & doors
 */
class CellDefinitions {
public:
	static const char Wall;
	static const char Start;
	static const char End;
	static const char Corridor;

	/**
	*	Returns information for the key of the specified door.
	*/
	KeyInfo* FindKeyForADoor(char doorSymbol);


	/**
	*	Marks the key as collected. We will be able to unlock the door.
	*/
	void MarkAsCollected(char key);

	/**
	*	Returns if the key for the specified door is returned.
	*/
	bool IsCollected(char doorSymbol);

	/**
	*	Add information for door and its key
	*/
	void AddDoorAndKey(char doorSymbol, KeyInfo keyCell);

	/**
	*	Update the location of the specified key
	*/
	void UpdateKeyLocation(char key, int row, int column);

	/**
	*	Determines whether the provided character is a key
	*/
	bool IsKey(char key);

	/**
	*	Determines whether the provided character is a door
	*/
	bool IsDoor(char door);

private:
	std::map<char, KeyInfo> doorsAndKeys;

};

#endif
