#include "unit.h"

namespace quantcore::time
{
    std::chrono::time_point<std::chrono::system_clock> TimePoint()
    {
        return std::chrono::system_clock::now();
    }

    std::chrono::time_point<std::chrono::system_clock> TimePoint(const uint16_t &year, const uint8_t &month, const uint8_t &day)
    {
        std::tm time = {};
        time.tm_year = year - 1900;
        time.tm_mon = month - 1;
        time.tm_mday = day;
        return std::chrono::system_clock::from_time_t(std::mktime(&time));
    }

    std::chrono::time_point<std::chrono::system_clock> TimePoint(const uint16_t &year, const uint8_t &month, const uint8_t &day, const uint8_t &hour, const uint8_t &minute, const uint8_t &second)
    {
        std::tm time = {};
        time.tm_year = year - 1900;
        time.tm_mon = month - 1;
        time.tm_mday = day;
        time.tm_hour = hour;
        time.tm_min = minute;
        time.tm_sec = second;
        return std::chrono::system_clock::from_time_t(std::mktime(&time));
    }

    std::chrono::time_point<std::chrono::system_clock> TimePoint(const std::string &str)
    {
        std::tm tm = {};
        std::istringstream ss(str);
        ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
        if (ss.fail())
        {
            throw std::runtime_error("Failed to parse datetime, Specified format: %Y-%m-%d %H:%M:%S");
        }
        return std::chrono::system_clock::from_time_t(std::mktime(&tm));
    }
}
