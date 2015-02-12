#ifndef BOARD_H
#define BOARD_H

#include <fstream>

class Board;

#include "Cell.h"
#include "CellDefinitions.h"

class Board
{
private:
	///
	///	A two-dimensional array, which holds all cells in the labyrinth
	///
	Cell** ppBoard;

	///	The number of rows in the board
	int RowsCount;

	///	The number of columns in the board
	int ColsCount;

	CellDefinitions cellDefinitions;

	int startRow;
	int startColumn;

private:
	Cell** AllocateNewBoard(int RowsCount, int ColsCount);
	void FreeBoard(Cell**& ppBoard, int RowsCount);
	Cell** DuplicateBoard(const Cell** ppBoard, int RowsCount, int ColsCount);
	Cell** DuplicateBoard(const Board & board);
	void SetAsOwnerFor(Cell** ppBoard, int RowsCount, int ColsCount);

private:
	static bool GetBoardDimensionsFromFile(std::ifstream & InputFile, int& RowsCount, int& ColsCount);
	void ReadBoardFromFile(std::ifstream & InputFile, Cell ** ppBoard);
	void FindDoorsAndKeys();

public:
	Board();
	Board(const Board & board);
	~Board();
	Board & operator=(Board const & board);

public:
	int GetRowsCount() const;
	int GetColsCount() const;

	bool LoadFromFile(const char* Filename);

	Cell* GetCell(int Row, int Col) const;
	Cell* GetStart() const;

	void Print() const;

	void MarkAllCellsNotVisited();
	CellDefinitions& GetDefinitions();
};

#endif // BOARD_H