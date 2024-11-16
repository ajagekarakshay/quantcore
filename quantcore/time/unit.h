#pragma once

#include <chrono>
#include <cstdint>
#include <string>
#include <sstream>
#include <iomanip>

namespace quantcore::time
{
    std::chrono::time_point<std::chrono::system_clock> TimePoint();

    std::chrono::time_point<std::chrono::system_clock> TimePoint(const uint16_t &year, const uint8_t &month, const uint8_t &day);

    std::chrono::time_point<std::chrono::system_clock> TimePoint(const uint16_t &year, const uint8_t &month, const uint8_t &day, const uint8_t &hour, const uint8_t &minute, const uint8_t &second);

    std::chrono::time_point<std::chrono::system_clock> TimePoint(const std::string &str);
}
