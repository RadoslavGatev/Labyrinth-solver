#ifndef KEYINFO_H
#define KEYINFO_H

struct KeyInfo {
public:
	KeyInfo(int row, int col, char caption) :row(row), col(col),
		caption(caption)
	{
		isColected = false;
	}

	int row;
	int col;
	char caption;
	bool isColected;
};

#endif