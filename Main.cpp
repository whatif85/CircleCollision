//#include "CircleMatrix.h"
#include "ConstevalCircleMask.h"
#include "Circle.h"
#include <chrono>
#include <iostream>

/*
int main()
{
	// Touching example
	auto startC1 = std::chrono::high_resolution_clock::now();
	//CircleMatrix c1(Position(5, 5), Size(2000, 2000), 7.0f);
	auto c1 = ConstevalCircleMask<200, 200, 5, 5, 7>::mask;
	// Record the ending time point
	auto endC1 = std::chrono::high_resolution_clock::now();
	// Calculate the duration and cast it to nanoseconds
	auto durationC1 = std::chrono::duration_cast<std::chrono::nanoseconds>(endC1 - startC1);
	std::cout << "Execution time: " << static_cast<double>(durationC1.count()) * 1e-3 << " microseconds" << std::endl;

	auto startC2 = std::chrono::high_resolution_clock::now();
	auto c2 = ConstevalCircleMask<300, 150, 10, 10, 10>::mask;
	//CircleMatrix c2(Position(10, 10), Size(3000, 1500), 10.0f);
	auto endC2 = std::chrono::high_resolution_clock::now();
	auto durationC2 = std::chrono::duration_cast<std::chrono::nanoseconds>(endC2 - startC2);
	std::cout << "Execution time: " << static_cast<double>(durationC2.count()) * 1e-3 << " microseconds" << std::endl;


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
*/

int main() {
	// Example 1: Intersecting circles
	auto circ1 = new Circle(Position(2, 3), 4.0);
	auto circ2 = new Circle(Position(1, 1), 3.0);
	std::cout << "--- Example 1 ---" << std::endl;
	circ1->CheckIntersection(*circ1, *circ2);

	std::cout << std::endl;

	// Example 2: Non-intersecting circles (separate)
	auto circ3 = new Circle(Position(0, 0), 1.0); // Center (0, 0), Radius 1
	auto circ4 = new Circle(Position(10, 10), 2.0 ); // Center (10, 10), Radius 2
	std::cout << "--- Example 2 ---" << std::endl;
	circ3->CheckIntersection(*circ3, *circ4);

	return 0;
}
