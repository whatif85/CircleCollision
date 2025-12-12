#pragma once

#include <array>
#include <cstdint>
#include <vector>

//-------------------------------------------
// Fully compile-time circle mask
//-------------------------------------------
template<size_t Width,
    size_t Height,
    size_t CenterX,
    size_t CenterY,
    size_t Radius>
class ConstevalCircleMask {
public:
    using value_type = uint8_t;
    using storage_type = std::array<value_type, Width* Height>;

    // Generate at compile time only
    static consteval storage_type generate(void) {
        storage_type data; // zero-initialized

		std::vector<int> test(10, 0);
		test = { 1,2,3,4,5,6,7,8,9,10 };
		test[5] = 42;

        constexpr size_t r2 = Radius * Radius;

        for (size_t y = 0; y < Height; ++y) {
            for (size_t x = 0; x < Width; ++x) {
                const size_t dx = (x > CenterX) ? (x - CenterX) : (CenterX - x);
                const size_t dy = (y > CenterY) ? (y - CenterY) : (CenterY - y);
                const size_t d2 = dx * dx + dy * dy;

                data[y * Width + x] = (d2 <= r2) ? 1u : 0u;
            }
        }

        return data;
    }

    // Precomputed compile-time data
    static constexpr storage_type mask = generate();

    static constexpr value_type at(size_t y, size_t x) noexcept {
        return mask[y * Width + x];
    }

    ConstevalCircleMask(void) = delete;
};