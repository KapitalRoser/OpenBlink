#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>

int main(){
int i = 0;
auto start = std::chrono::high_resolution_clock::now();
bool skipped = false;
std::vector<int>bads;
while(i < 10000){
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    if (duration.count() > i + 1){
        bads.push_back(i);
    }
    if (duration.count() > i){
        std::cout << std::setw(6) << duration.count() << "\r";
        i = duration.count();
    }
}

if (bads.empty()){
    std::cout << "SKIP!\n";
    
    for(int i : bads){
    std::cout << bads[i] << ",";
}
} else {
    std::cout << "SUCCESS!";
}

//results, success! Should be guaranteed to go through each ms individually at least once. 
}