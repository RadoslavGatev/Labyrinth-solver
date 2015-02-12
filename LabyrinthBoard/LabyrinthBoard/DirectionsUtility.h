#ifndef DIRECTIONSUTILITY_H
#define DIRECTIONSUTILITY_H

class DirectionsUtility {
public:
	static constexpr char Left = 'L';
	static constexpr char Right = 'R';
	static constexpr char Up = 'U';
	static constexpr char Down = 'D';

	static  char GetReverse(char direction)
	{
		switch (direction)
		{
		case Left: return Right; break;
		case Right: return Left; break;
		case Up: return Down; break;
		case Down: return Up; break;
		}

		return ' ';
	}
};

#endif