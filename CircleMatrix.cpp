#include "CircleMatrix.h"

void CircleMatrix::Generate()
{
    for (std::size_t y = 0; y < size.height; ++y)
    {
        for (std::size_t x = 0; x < size.width; ++x)
        {
            const std::size_t dx = x - position.x;
            const std::size_t dy = y - position.y;
            const double d2 = pow(dx, 2) + pow(dy, 2);

            data[y * size.width + x] = (static_cast<float>(d2) <= radius2) ? 1u : 0u;
        }
    }
}
