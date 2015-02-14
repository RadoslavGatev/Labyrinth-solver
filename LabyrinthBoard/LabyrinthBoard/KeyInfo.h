#ifndef KEYINFO_H
#define KEYINFO_H

/**
*	Stores information for a key
*/
struct KeyInfo {
public:
	KeyInfo(int row, int col, char caption) :row(row), col(col),
		caption(caption)
	{
		isColected = false;
	}

	int row;
	int col;

	/**
	*	The symbol which represents the key in the labyrinth
	*/
	char caption;
	bool isColected;
};

#endif