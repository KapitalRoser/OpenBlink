#include <iostream>
#include <thread>
#include <chrono>

void runTimer(int limit, int threadNumber){
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::seconds duration;
    std::chrono::seconds previous;
    bool timerRunning = true;
    while(timerRunning){
        auto curTime = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::seconds>(curTime - start);
        if (duration.count() != previous.count()){
            previous = duration;
            std::cout << "T: " << previous.count() << " Thread #: " << threadNumber << "\n";
        }
        if (duration.count() >= limit){
            timerRunning = false;
        }
        }
    std::cout << "Complete!";
}

void thread_function(int threadNumber)
{
    //this is thread space
    std::cout << "thread function\n";
    runTimer(10,threadNumber);
}

int main()
{
    std::thread t(&thread_function, 1);
    std::cout << "Waiting!\n";
    //this is main thread space.
    //countdown
    runTimer(15,0);


    
    if (t.joinable()){
        t.join();
    } 

    std::cout << "\nTOOL Complete!";
    return 0;
}