#include "Circle.h"

Circle::Circle(Position pos, double radius)
    : pos(pos), radius(radius)
{}

double Circle::CalculateDistance(const Circle& c1, const Circle& c2)
{
    const double dx = c1.pos.x - c2.pos.x;
    const double dy = c1.pos.y - c2.pos.y;
    // Use std::sqrt and power (or simply multiplication) for the distance formula
    return sqrt(dx * dx + dy * dy);
}

void Circle::CheckIntersection(const Circle& c1, const Circle& c2)
{
    const double d = CalculateDistance(c1, c2);
    const double sumRadii = c1.radius + c2.radius;
    const double diffRadii = abs(c1.radius - c2.radius);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Distance between centers (d): " << d << std::endl;
    std::cout << "Sum of radii (r1 + r2): " << sumRadii << std::endl;
    std::cout << "Absolute difference of radii (|r1 - r2|): " << diffRadii << std::endl;

    if (d > sumRadii) {
        std::cout << "Result: The circles do not intersect (they are separate)." << std::endl;
    }
    else if (d < diffRadii) {
        std::cout << "Result: One circle is contained entirely within the other without touching." << std::endl;
    }
    else if (d == sumRadii) {
        std::cout << "Result: The circles touch at exactly one point externally (tangent)." << std::endl;
    }
    else if (d == diffRadii) {
        std::cout << "Result: The circles touch at exactly one point internally (tangent)." << std::endl;
    }
    else {
        std::cout << "Result: The circles intersect at two points." << std::endl;
    }
}