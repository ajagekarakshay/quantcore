#include <gtest/gtest.h>
#include <chrono>
#include <string>

#include <quantcore/qc.h>

TEST(TimePointTest, DefaultConstructor)
{
    auto now = qc::time::TimePoint();
    auto system_now = std::chrono::system_clock::now();

    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(system_now - now).count();
    EXPECT_LT(std::abs(diff), 1000);
}

TEST(TimePointTest, DateConstructor)
{
    auto tp = qc::time::TimePoint(2024, 3, 15);

    std::time_t time = std::chrono::system_clock::to_time_t(tp);
    std::tm *tm = std::gmtime(&time);

    EXPECT_EQ(tm->tm_year, 2024 - 1900);
    EXPECT_EQ(tm->tm_mon, 2); // 0-based month
    EXPECT_EQ(tm->tm_mday, 15);
}

TEST(TimePointTest, DateTimeConstructor)
{
    auto tp = qc::time::TimePoint(2024, 3, 26, 14, 30, 45);

    std::time_t time = std::chrono::system_clock::to_time_t(tp);
    std::tm *tm = std::gmtime(&time);

    EXPECT_EQ(tm->tm_year, 2024 - 1900);
    EXPECT_EQ(tm->tm_mon, 2);
    EXPECT_EQ(tm->tm_mday, 26);
}

TEST(TimePointTest, StringConstructor)
{
    auto tp = qc::time::TimePoint("2024-03-15 14:30:45");

    std::time_t time = std::chrono::system_clock::to_time_t(tp);
    std::tm *tm = std::gmtime(&time);

    EXPECT_EQ(tm->tm_year, 2024 - 1900);
    EXPECT_EQ(tm->tm_mon, 2);
    EXPECT_EQ(tm->tm_mday, 15);
    EXPECT_EQ(tm->tm_sec, 45);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}