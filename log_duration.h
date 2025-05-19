#pragma once
#include <chrono>
#include <iostream>
#define PROFILE_CONCAT_INTERNAL(X, Y) X##Y
#define PROFILE_CONCAT(X, Y) PROFILE_CONCAT_INTERNAL(X, Y)
#define UNIQUE_VAR_NAME_PROFILE PROFILE_CONCAT(profileGuard, __LINE__)
#define LOG_DURATION(x) LogDuration UNIQUE_VAR_NAME_PROFILE(x)
class LogDuration
{
  public:
    using Clock = std::chrono::steady_clock;
    explicit LogDuration(const std::string &id) : id_(id)
    {
    }
    ~LogDuration()
    {
        using namespace std::chrono;
        using namespace std::literals;
        const auto end_time = Clock::now();
        const auto dur = end_time - start_time_;
        std::cerr << id_ << " : "s;
        int64_t duration = duration_cast<microseconds>(dur).count();
        if (duration >= 1000000)
        {
            std::cerr << duration / 1000000 << "s "s;
        }
        if (duration >= 1000)
        {
            std::cerr << (duration / 1000) % 1000 << "ms "s;
        }
        std::cerr << duration % 1000 << "mcs "s << std::endl;
    }

  private:
    const std::string id_;
    const Clock::time_point start_time_ = Clock::now();
};
