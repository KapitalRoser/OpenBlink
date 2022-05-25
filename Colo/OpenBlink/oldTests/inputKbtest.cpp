#include <iostream>
#include <string>
#include <future>
#include <thread>
#include <chrono>
#include <conio.h>
#include <stdio.h>

int main()
{

    int point = 0;
    char buffer[512];

    std::cout << "Start\n";
auto start = std::chrono::high_resolution_clock::now();
int limit = 0;
while (limit < 6000){
auto stop = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    if (kbhit()){
        std::cout << duration.count() << std::endl;
        getch();
    }
limit = duration.count();
}




    // std::cout << "GetChar";
    // getchar();
    std::cout << "End!";






 return 0;   
}    