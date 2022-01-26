#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
//XD TOOL NOT COLO
#include "../../processCore.h"
using namespace std;

void printResults(int anomalies, std::vector<int>stepFrames, ofstream &refinedPattern){
    refinedPattern << "Anomalies: " << anomalies << ".\n";
    refinedPattern << "Step frames: ";
    for (unsigned int i = 0; i<stepFrames.size();i++){
      refinedPattern << stepFrames.at(i) << ",";
    }
    refinedPattern << ".\n";
    cout << "Output file produced! All done!";
    refinedPattern.close();
}

int main(){
    const string FILE_EXTENSION = ".txt";
    string FILE_NAME = "";
    cout << "Enter filename: ";
    getline(cin, FILE_NAME);
    int rolls = 0;
    uint32_t seed = 0x0;

    //Colo-Specific identifiers
    const int hiFrame = 116;
    const int loFrame = 76;
    const int yFrame = 154; //PAL Only
    const int xFrame = 114;
    
    vector<int> stepValues = {};

    int anomalies = 0;
    bool npcsON = 0;
    int region = 0; //0 NTSC, 1 EU, 2 NSTCJ
    string frameType = "";
    vector<int>stepFrames;
    //File IN
    vector<uint32_t> rawPattern = hexReadNumbersFromFile(FILE_NAME + FILE_EXTENSION);
    //File OUT
    ofstream refinedPattern("out" + FILE_NAME + FILE_EXTENSION);
    refinedPattern << std::hex; 
    ofstream purePattern("outPure" + FILE_NAME + FILE_EXTENSION);

    if (rawPattern.empty()){
        cout << "File read unsuccessful";
    } else {
        cout << "File read successfully! ";
    }
    cout << "Values read: " << rawPattern.size() << endl;
    for (uint32_t i = 0; i<rawPattern.size()-1;i++){
        seed = rawPattern.at(i); // Compares a given seed to the next seed in the list. 
        
        //Search
        rolls = 0;
        while(seed != rawPattern.at(i+1)){
            LCG(seed);
            rolls++;
        }
        //std::cout << rolls << "\n";
        //For output document only
        //write results
        if (rolls != 0){
            refinedPattern << rawPattern.at(i) << "\n";
            //purePattern << rolls << endl;
        }
        
    }
    printResults(anomalies,stepFrames,refinedPattern);
    return 0;
    }
