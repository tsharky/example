module;

import std;

export module syslog;

namespace syslog
{

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
void log(const Level level, std::format_string<Args...> fmt, Args&&... args) {
    using namespace std::chrono;
    const auto now = floor<seconds>(system_clock::now());
    const auto localTime = zoned_time{current_zone(), now};
    std::print("{:%FT%T%Ez} ", localTime);
    std::print("{}: ", static_cast<char>(level));
    std::println(fmt, std::forward<Args>(args)...);
}

export template <typename... Args>
void fatal(std::format_string<Args...> fmt, Args&&... args) {
    log(Level::Fatal, fmt, std::forward<Args>(args)...);
}

export template <typename... Args>
void error(std::format_string<Args...> fmt, Args&&... args) {
    log(Level::Error, fmt, std::forward<Args>(args)...);
}

export template <typename... Args>
void warning(std::format_string<Args...> fmt, Args&&... args) {
    log(Level::Warning, fmt, std::forward<Args>(args)...);
}

export template <typename... Args>
void info(std::format_string<Args...> fmt, Args&&... args) {
    log(Level::Info, fmt, std::forward<Args>(args)...);
}

export template <typename... Args>
void note(std::format_string<Args...> fmt, Args&&... args) {
    log(Level::Note, fmt, std::forward<Args>(args)...);
}

/// @brief Logs a message with the debug level.
/// @tparam ...Args
/// @param fmt
/// @param ...args
/// @note This function is only available in debug builds. In release builds, it will be removed by the preprocessor.
export template <typename... Args>
void debug([[maybe_unused]] std::format_string<Args...> fmt, [[maybe_unused]] Args&&... args) {
#ifndef NDEBUG
    log(Level::Debug, fmt, std::forward<Args>(args)...);
#endif
}

} // namespace syslog
