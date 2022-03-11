#ifndef UTILITY_ERROROR_H
#define UTILITY_ERROROR_H

template<typename T>
struct [[nodiscard]] ErrorOr {
    int32_t r = -1;
    T val;

    constexpr bool isOk() noexcept { return r >= 0; }

    constexpr bool isErr() noexcept { return !isOk(); }
};

#endif //UTILITY_ERROROR_H
