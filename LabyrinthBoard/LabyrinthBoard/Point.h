#ifndef POINT_H
#define POINT_H

struct Point {
	int row;
	int col;
	char direction;

	Point()
	{
		row = -1;
		col = -1;
	}

	Point(int row, int col, char direction)
	{
		this->row = row;
		this->col = col;
		this->direction = direction;
	}

	bool IsNull()
	{
		return row == -1 || col == -1;
	}
};

#endif
