////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <random>
#include <string>
#include <thread>
#include <vector>

#ifdef _WIN32
#   include <Windows.h>
#else
#   include <unistd.h>
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
void callback(std::string& threadName)
{
    std::random_device randomDevice;
    std::default_random_engine randomEngine(randomDevice());
    std::uniform_int_distribution<int> uniform_dist(100, 3000);
    int milliseconds = uniform_dist(randomEngine);

    std::string string;
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);  /* sleep for 100 milliSeconds */
#endif
    string =
            "\"" + threadName + "\""
            + " completed after: " + std::to_string(milliseconds) + " milliseconds.\n";
    std::cout << string;
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
int main()
{
    std::vector<std::thread> threads;

    for (int current = 0; current < 10; ++current)
    {
        threads.push_back(std::thread(callback, std::to_string(current)));
    }

    for (auto& thread: threads)
    {
        thread.join();
    }

    return 0;
}
////////////////////////////////////////////////////////////////////////////////
