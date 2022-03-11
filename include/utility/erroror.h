#ifndef RAMMELO_ERROROR_H
#define RAMMELO_ERROROR_H

#include <cstdint>

template<typename T>
struct [[nodiscard]] ErrorOr {
    int32_t r = -1;
    T val;

    constexpr bool isOk() noexcept { return r >= 0; }

    constexpr bool isErr() noexcept { return !isOk(); }
};

#endif //RAMMELO_ERROROR_H
