#include "CircleMatrix.h"

int main()
{
	CircleMatrix c1(Position(5, 5), Size(20, 20), 7.0f);

	// Touching example
	CircleMatrix c2(Position(10, 10), Size(30, 15), 10.0f);
	// Non-Touching example (Uncomment to test)
	//CircleMatrix c2(Position(80, 80), Size(30, 15), 10.0f);

	// Check if the two circles are touching
	if (c1(Position(5, 5)) && c2(Position(10, 10)))
	{
		printf("The circles are touching at their centers.\n");
	}
	else
	{
		printf("The circles are not touching at their centers.\n");
	}

	return 0;
}
