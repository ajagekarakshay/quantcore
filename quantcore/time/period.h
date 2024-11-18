#pragma once

#include <chrono>
#include <cstdint>
#include "time/unit.h"

namespace qc::time
{
    using Day = std::chrono::duration<int64_t, std::ratio<86400>>;
    using Hour = std::chrono::duration<int64_t, std::ratio<3600>>;
    using Minute = std::chrono::duration<int64_t, std::ratio<60>>;
    using Second = std::chrono::duration<int64_t, std::ratio<1>>;
    using Millisecond = std::chrono::duration<int64_t, std::ratio<1, 1000>>;

    struct Period
    {
        std::chrono::time_point<std::chrono::system_clock> start;
        std::chrono::time_point<std::chrono::system_clock> end;

        Period(const std::chrono::time_point<std::chrono::system_clock> &start, const std::chrono::time_point<std::chrono::system_clock> &end);
    };
}
