#include "head/alpha.h"

#include <thread>
#include <future>
#include <iostream>
#include <string> 
#include <chrono>

namespace factory
{

int foo(int b)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    utils::Logger::Message(std::to_string(b));
    std::this_thread::sleep_for(std::chrono::seconds(1));
    utils::Logger::Message(std::to_string(b));
    return 5;
}

int run(int argc, char *argv[])
{
    std::vector<utils::Logger> tokens;
    for(auto i = 0; i < 5; i++)
        tokens.emplace_back([i](){return foo(i);});
    // auto future = std::async(foo, 3, 4);
    utils::Logger::Message("A");
    for(auto& t: tokens)
        t.Join();
    utils::Logger::Message("B");
    // std::cout << future.get() << std::endl;
    return 0;
}

}