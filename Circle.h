#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>


struct Position
{
public:
    std::size_t x;
    std::size_t y;

    Position(std::size_t x, std::size_t y)
        : x{ x }, y{ y }
    {
    }
};


class Circle
{
public:
    Position pos;
	double radius;

    Circle() = delete;
    Circle(Position pos, double radius);
    ~Circle() = delete;

    // Function to calculate the distance between the centers of two circles
    double CalculateDistance(const Circle& c1, const Circle& c2);

    // Function to check for intersection and describe the relationship
	void CheckIntersection(const Circle& c1, const Circle& c2);
};
