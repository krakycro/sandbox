#ifndef LOGGER_H
#define LOGGER_H

#include <thread>

#include <iostream>

namespace utils
{

enum class ExitStatus : int
{
    ok_status = 0,
    error_unexpected,
    warning_detected,
};

class Logger: std::thread
{
  public:
    inline static std::string buffer;

    template <typename Fn, typename... Args>
    explicit Logger(Fn&& fn, Args&&... arg) : std::thread{fn, arg...}
    {
        std::cout << "start" << std::endl;
    }
    Logger (const Logger&) = delete;
    Logger (Logger&& x) noexcept = default;

    ~Logger()
    {
        std::cout << "end" << std::endl;
        std::cout << ">" + Logger::buffer + "<" << std::endl;
    }

    void Join()
    {
        this->join();
    }

    static void Message(std::string msg)
    {
        Logger::buffer.append(msg);
    }
};

}

#endif // LOGGER_H
