#ifndef SYSLOG_SYSLOG_HPP
#define SYSLOG_SYSLOG_HPP

#include <chrono>
#include <print>

namespace syslog {

namespace detail {

enum class Level : char
{
    Fatal = 'F',
    Error = 'E',
    Warning = 'W',
    Info = 'I',
    Note = 'N',
    Debug = 'D'
};

template <typename... Args>
void log(const Level level, std::format_string<Args...> fmt, Args&&... args)
{
    using namespace std::chrono;
    const auto now = floor<seconds>(system_clock::now());
    const auto localTime = zoned_time{current_zone(), now};
    std::print("{%FT%T%Ez} ", localTime);
    std::print("{}: ", static_cast<char>(level));
    std::println(fmt, std::forward<Args>(args)...);
}

} // namespace detail

template <typename... Args>
void fatal(std::format_string<Args...> fmt, Args&&... args) {
    detail::log(Level::Fatal, fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void error(std::format_string<Args...> fmt, Args&&... args) {
    detail::log(Level::Error, fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void warning(std::format_string<Args...> fmt, Args&&... args) {
    detail::log(Level::Warning, fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void info(std::format_string<Args...> fmt, Args&&... args) {
    detail::log(Level::Info, fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void note(std::format_string<Args...> fmt, Args&&... args) {
    detail::log(Level::Note, fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void debug([[maybe_unused]] std::format_string<Args...> fmt, [[maybe_unused]] Args&&... args) {
#ifndef NDEBUG
    detail::log(Level::Debug, fmt, std::forward<Args>(args)...);
#endif
}

} // namespace syslog

#endif // SYSLOG_SYSLOG_HPP
