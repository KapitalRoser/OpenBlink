#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <queue>


struct thrMsg {
    int SLB = 0;
};

//can we avoid these globals?
std::condition_variable cv;
std::mutex m;
std::queue<thrMsg> msg_queue;



void runTimer(int limit){
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::seconds duration;
    std::chrono::seconds previous;
    bool timerRunning = true;
    while(timerRunning){
        auto curTime = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::seconds>(curTime - start);
        if (duration.count() != previous.count()){
            previous = duration;
            std::cout << "T: " << previous.count() << " Thread #: " << std::this_thread::get_id() << "\n";
        }
        if (duration.count() >= limit){
            timerRunning = false;
        }
        }
    std::cout << "Complete!";
}

void sendMessage(const thrMsg& message) {
    std::lock_guard<std::mutex> lk(m); //acquires the mutex variable. lk is popped at end of function.
    msg_queue.push(message); //adds message to global message queue. first in, first out.
    cv.notify_one(); //wakes up any threads that are waiting. can also notify_all.
}

thrMsg GetMessage() {
    thrMsg message; //define incoming
    std::unique_lock<std::mutex> lock(m); //aquire mutex, lock is popped at the end of function.
    cv.wait(lock, [](){return !msg_queue.empty();}); //holds thread until the queue isn't empty. 
    //Releases mutex to suspend thread. Upon wakeup,  mutex is automatically re-acquired. Condition is then checked after getting the mutex. 
    message = msg_queue.front(); //takes msg from queue. 
    msg_queue.pop(); //first-in, first-out.
    return message;
}

void receiveFunc()
{
    //this is thread space
    std::cout << "Waiting for msg...\n";
    thrMsg msg = GetMessage();
    std::cout << "Received: " << msg.SLB << std::endl;
}
void senderFunc(){
    thrMsg payload;
    runTimer(10);
    //send dat boi
    payload.SLB = 54;
    sendMessage(payload);



}

int main()
{
    bool threadDone = false;
    thrMsg messageForThread;
    std::thread t(&receiveFunc);
    std::thread sender(&senderFunc);
    std::cout << "Waiting!\n";
    //this is main thread space.
    //countdown
    runTimer(15);
    if (threadDone){
        std::cout << "THREAD FINISHED!\n"; 
    }


    t.join();
    sender.join();

    std::cout << "\nTOOL Complete!";
    return 0;
}