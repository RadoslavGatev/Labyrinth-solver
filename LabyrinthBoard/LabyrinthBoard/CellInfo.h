#ifndef CELLINFO_H
#define CELLINFO_H

struct CellInfo {
public:
	CellInfo(int row, int col, char caption) :row(row), col(col),
		caption(caption)
	{ }

private:
	int row;
	int col;
	char caption;
};

#endif