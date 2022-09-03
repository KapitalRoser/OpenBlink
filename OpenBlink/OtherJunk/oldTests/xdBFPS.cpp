#include "../../../processCore.h"

int main(){
    std::string testnum = "";
    std::getline(std::cin,testnum);
    std::ifstream inData ("pXD" + testnum + ".txt");
    std::ofstream outData ("oXD" + testnum + ".txt");
    std::vector<float>dataSet;
    std::vector<int>gaps;
    float value = 0;
    //basic file parsing
    while(!inData.fail()){
        inData >> value;
        dataSet.push_back(value);
    }
    inData.close();

    int sumFailuresMore = 0;
    int sumFailuresLess = 0;
    int sumFailuresTotal = 0;
    bool startingVal = 0;
    if (dataSet.front() >= 1){
        startingVal = 1;
    } else {
        startingVal = 0;
    }
    for (unsigned int i = 0; i < dataSet.size(); i++)
    {
        if (i % 2 == startingVal){
           if (dataSet.at(i) >= 1){
            outData << "Failure 1: " << i << "\n";
            gaps.push_back(i);
            sumFailuresMore++;
           }
        } else {
            if (dataSet.at(i) < 1){
                outData << "Failure 0.9: " << i << "\n";
                gaps.push_back(i);
                sumFailuresLess;
            }
        }
    }
    outData << "Total failures: " << sumFailuresLess+sumFailuresMore;
    outData.close();
    debugPrintVec(gaps);
    //seems like enough of a pattern on it's own, something to work with.
    //1-1-9-1-1-9 etc. 
    //Just need to nail down the when.




    return 0;
}