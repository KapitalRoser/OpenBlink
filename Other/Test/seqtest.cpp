#include "processCoreBlink.h"
#include "blinkbase.h"


/* INSIGHTS

    - Seed 0 seems to be a stable genesis for a baseline pattern of blinks.
    - Most seeds instantly converge at 0.
    - Exponential slope downward of occurrences of "weird" seeds that cause instability.
    - So far worst convergence observed is 5 blinks. 
    - Only needs 1 blink to match the baseline, then can feel safe.
    - 82,341,044 blinks looks to be the magic constant. This is the number of blinks produced across the whole u32 set, starting from a stable seed.

*/



void createTheHolyOrder(u32 initSeed,platform plat, std::vector<pool>&THE_HOLY_POOL, double limit){
    u32 seed = initSeed;
    std::cout << "Starting generation!\n";
    THE_HOLY_POOL = generateBlinks(seed,plat,limit); //This last variable expands massively due to limit++ in gen.blinks, need to monitor.
    std::cout << "DONE! Size: ";
    std::cout << THE_HOLY_POOL.size();
}

void printPoolVec(std::vector<pool> vpool){
    for (int i = 0; i < vpool.size(); i++)
    {
        int spot = i;
        std::cout << std::dec << "(" << vpool.at(i).blink << ", " << std::hex << vpool.at(i).seed << ")" << ", ";
    }
}

int simpleSearch (u32 term, int start, const std::vector<pool>& bPool){
    for (int i = start; i < 200+start; i++){ //For performance reasons, if you don't find the seed within 5000 advances, ya not gonna find it.
        u32 bP = bPool.at(i).seed;
        if (term == bP){
            return i;//WINNER
        }
    }
    return -1;
}

u32 convergeTest(int testNum, u32 seed, platform plat, std::vector<pool>&bPool, std::vector<int>&fac, int numVecs, int testLim, int &start) {
    
    for (int i = 0; i < numVecs; i++)
    {
        if (i % 95 == 0 && i > 0) {
            start++;
        }
        LCG(seed);
        //int till0 = findGapConfident(seed,0,1);
        if (seed == 0){
            return 0;
        }
        std::vector<pool> cmpPool = generateBlinks(seed,plat,testLim);
        //validation:
        iterP x = cmpPool.begin();
        while (x <= cmpPool.end()){
            int found = simpleSearch(x->seed,start,bPool);
            if (found >=0){
                // if (i % 100 == 0){
                //     std::cout << "vec #i: " << i 
                //     << " in cmp: " << x-cmpPool.begin() 
                //     << ". In baseline: " << found  
                //     << " start at: " << start 
                //     << ". Gap: " << found-start<< std::endl;  
                // }
                
                if ((found - start) > 50){
                    //std::cout << "Adjust: " << found-start << "-----------\n";
                    start += 25;
                }
                fac.push_back(x-cmpPool.begin());
                break;
            }
            if (x == cmpPool.end()){
                fac.push_back(-1);
            }
            x++;
        }
        //if (i % 1000 == 0) {std::cout << "TestNum: " << testNum << " i:" << i << std::endl;}
    }
    if (testNum % 10 == 0) {
        std::cout << "\nTestNum: " << testNum << " complete!~~~~~~~ ";
    }
    return seed;
}

void printResults(const std::vector<int>&bcf){
    //std::cout << "RESULTS: \n";
    //debugPrintVec(blinkConvergenceFactor);
    int max = 0;
    double mean = 0;
    int hist[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int fails = 0;
    for (int x : bcf){
        if (x == -1){
            fails++;
        } else {
            hist[x]++;
        }
        
        if (x > max){
            max = x;
        }
        mean += x;
    }
    mean /= bcf.size();

    //sorted now.
    std::cout << std::dec << "Vec Size: " << bcf.size()  << " Largest: " << max << " ";
    //std::cout << " Mean: " << mean << std::endl;
    std::cout << "Counts: ";
    for (int i = 0; i < 30; i++){
        std::cout << hist[i] << " ";
    }
    std::cout << " Fails: " << fails;
}
void writeF(const std::vector<pool>THE_HOLY_ORDER){
    std::ofstream holyFile;
    holyFile.open("THE_HOLY_ORDER_x.txt");
    for (int i = 0; i < 10; i++){
        holyFile << THE_HOLY_ORDER.at(i).seed << "," << THE_HOLY_ORDER.at(i).blink << std::endl;
    }
    holyFile.close();
}

void readF(std::vector<pool>&THE_HOLY_ORDER){
    //can possibly optimize to get rid of delimiter (alternating rows) to reduce filesize... 1GB rn...
    std::ifstream holyFile;
    holyFile.open("THE_HOLY_ORDER_BLINKS.txt");
    u32 a;
    int b;
    char c;
    std::vector<std::string> data;
    while ((holyFile >> a  >> c >> b) && (c == ',') ){
        pool x;
        x.blink = b;
        x.seed = a;
        THE_HOLY_ORDER.push_back(x);
    }
    holyFile.close();
}

int main(){

    //first we test colo
    u32 const INIT_SEED = 0; //creative IK.
    //LCGn(seed,100'000);
    platform plat = platform(0,0,NTSCU);
    
    //convergeTest(plat);
    std::vector<int> blinkConvergenceFactor;
    //std::cout << "generating!";
    std::vector<pool> THE_HOLY_ORDER;
    u32 xSeed = 0;
    LCGn(xSeed, 4'000'000'000);

    createTheHolyOrder(xSeed,plat,THE_HOLY_ORDER,400'000'000);
    // for (int i = 0; i<4; i++){
    //     createTheHolyOrder(xSeed,plat,THE_HOLY_ORDER,1'000'000'000);
    //     std::cout << "SIZE: " << THE_HOLY_ORDER.size();
    //     THE_HOLY_ORDER.clear();
    //     xSeed = 0;
    //     LCGn(xSeed,1'000'000'000*(i+1));
    // }
    
    /*
    19172026
    19171506
    19168042
    19175429
    */


    
    double testLim = 2'000;
    int numVecs = 10'000;
    //std::vector<pool> baselinePool = generateBlinks(seed,plat,testLim);
    //debug
    // std::cout << "\ndone! Pool size: " << THE_HOLY_ORDER.size() << ". Blinks: ";
    // //printPoolVec(baselinePool);
    // std::cout << ". Final seed: " << std::hex << THE_HOLY_ORDER.back().seed << std::dec << std::endl; 

    //writeF(THE_HOLY_ORDER);
    //std::cout << "<READING>";
    auto start = std::chrono::high_resolution_clock::now();
    //readF(THE_HOLY_ORDER);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    // std::cout << "VERIFY: " << THE_HOLY_ORDER.size() << " in: " << duration.count();
    // //printPoolVec(THE_HOLY_ORDER);


    std::cout << "\nBEGIN BIG TEST!\n"; //Num blinks required to produce a seed found in the baseline pool.
    u32 seed = 0;
    LCGn(seed, 4'000'000'000);
    int searchStart = 0; //Not same number...
    int finalHist[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int fails = 0;
    start = std::chrono::high_resolution_clock::now();
    auto start2 = start;
    for (int i = 0; i < 100'000; i++)
    {
        u32 lastSeed = convergeTest(i,seed,plat,THE_HOLY_ORDER,blinkConvergenceFactor,numVecs,testLim,searchStart);
        if (lastSeed == 0){
            std::cout << "\nZERO REACHED!\n";
            break;
        }
        if (i % 1000 == 0) {
            stop = std::chrono::high_resolution_clock::now();
            auto durationTotal = std::chrono::duration_cast<std::chrono::seconds>(stop-start);
            auto durationInterim = std::chrono::duration_cast<std::chrono::seconds>(stop-start2);
            start2 = std::chrono::high_resolution_clock::now();
            std::cout << "~~~~~ TIME: " << durationInterim.count() << " seconds elapsed since previous." << durationTotal.count() << " seconds elapsed in total.\n";
            std::cout << "Dist to zero: " << findGapConfident(seed,0x0,true) << " ";
            for (int x : blinkConvergenceFactor){
                if (x == -1){
                    fails++;
                } else {
                    finalHist[x]++;
                }
            } 
            int max = 0;
            while (max < 30 && finalHist[max] != 0){
                max++;
            }
            max--; //adjust for 0 index.
            
            std::cout << std::dec << "Vec Size: " << blinkConvergenceFactor.size()  << " Largest: " << max << " ";
            std::cout << "Counts: ";
            for (int i = 0; i < 30; i++){
                std::cout << finalHist[i] << " ";
            }
    std::cout << " Fails: " << fails;
            blinkConvergenceFactor.clear();
            blinkConvergenceFactor.shrink_to_fit();
            
        }
        LCGn(seed,10'000);
    } //100,000 * 10'000 = 100M... this should be safer on my ram....


    for (int x : blinkConvergenceFactor){
            if (x == -1){
                fails++;
            } else {
                finalHist[x]++;
            }
        }
    std::cout << "\n\n FULLY COMPLETE! RESULTS: ";
    for (int i = 0; i < 30; i++){
        std::cout << " " << finalHist[i];
    }
    std::cout << ". Fails: " << fails;
    std ::cout << "\n Seed: " << seed;
    /*
    Vec Size: 700 000 Largest: 9 Mean: 0.502106
    Counts: 467057 154115 51861 18142 6095 1920 552 157 89 12 0 0 0 0 0 0 0 0 0 0

    Vec Size: 500 000 Largest: 9 Mean: 0.49143
    Counts: 336389 109089 35962 12147 4433 1423 491 61 4 1 0 0 0 0 0 0 0 0 0 0

    Vec Size: 500000 Largest: 10 Mean: 0.496184
    Counts: 335552 109198 36955 12011 3890 1486 547 225 122 12 2 0 0 0 0 0 0 0 0 0

    Vec Size: 500000 Largest: 8 Mean: 0.50393
    Counts: 331489 110965 39038 12947 4220 949 309 60 23 0 0 0 0 0 0 0 0 0 0 0

    Vec Size: 500000 Largest: 8 Mean: 0.475006
    Counts: 336682 110033 37861 11245 3125 860 147 45 2 0 0 0 0 0 0 0 0 0 0 0



    */
    
















  

    // 82,341,044 seems consistent?

    return 0;
}