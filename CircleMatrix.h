#pragma once

#include <vector>
#include <cstddef>
#include <cstdint>
#include <cmath>


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

struct Size
{
public:
    std::size_t width;
    std::size_t height;

    Size(std::size_t w, std::size_t h)
        : width{ w }, height{ h }
    {
    }
};

//-------------------------------------------
// Runtime circle matrix class
//-------------------------------------------
class CircleMatrix
{
private:
    Position position;
    Size size;
    float radius2;
    std::vector<std::uint8_t> data;

public:
    CircleMatrix(Position pos, Size size, float radius)
        : position{ pos }, size(size), radius2{ radius * radius }, data(size.width* size.height, 0)
    {
        Generate();
    }

    inline std::size_t GetWidth() const noexcept { return size.width; }

    inline std::size_t GetHeight() const noexcept { return size.height; }

    // Access pixel at (x, y)
    inline std::uint8_t operator()(Position pos) const noexcept { return data[pos.y * size.width + pos.x]; }

    inline const std::vector<std::uint8_t>& GetRawData() const noexcept { return data; }

private:
    void Generate();
};
