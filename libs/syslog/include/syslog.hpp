#ifndef SYSLOG_SYSLOG_HPP
#define SYSLOG_SYSLOG_HPP

#include <chrono>
#include <print>

namespace syslog {

namespace detail {

template <typename... Args>
void log(std::format_string<Args...> fmt, Args&&... args)
{
    using namespace std::chrono;
    const auto now = floor<seconds>(system_clock::now());
    const auto localTime = date::current_zone()->to_local(now);
    std::print("{} ", date::format("%FT%TZ", localTime));
    std::print(fmt, std::forward<Args>(args)...);
}

} // namespace detail

} // namespace syslog

#endif // SYSLOG_SYSLOG_HPP
