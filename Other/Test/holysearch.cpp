#include "processCoreBlink.h"
#include "blinkbase.h"
#include <charconv>

// typedef std::chrono::milliseconds T_MS;
// typedef std::chrono::seconds T_S;
// typedef std::chrono::minutes T_M;
// typedef std::chrono::hours T_H;


// template <typename T, typename X> //Unit, Return type.
// auto time(X *f, X& returnValue){ //may not have any arguments. Has return type.
//     auto start = std::chrono::high_resolution_clock::now();
//     returnValue = f();
//     auto stop = std::chrono::high_resolution_clock::now();
//     return std::chrono::duration_cast<T>(stop - start).count();
// }


void readF(std::vector<pool>&THE_HOLY_ORDER){
    //can possibly optimize to get rid of delimiter (alternating rows) to reduce filesize... 1GB rn...
    std::ifstream holyFile;
    holyFile.open("THE_HOLY_ORDER_BLINKS.txt");
    u32 a;
    int b;
    char c;
    std::vector<std::string> data;
    double linesLimit = 5'000'000'000;
    double curLines = 0;
    const int SIZE_OF_ORDER = 82'341'044;
    THE_HOLY_ORDER.reserve(SIZE_OF_ORDER);
    while ((holyFile >> a  >> c >> b) && (c == ',') && curLines <linesLimit ){
        // pool x;
        // x.blink = b;
        // x.seed = a;
        THE_HOLY_ORDER.emplace_back(b,a);
        curLines++;
    }
    holyFile.close();
}
void readF2(std::vector<pool>&THE_HOLY_ORDER){
    //functionally the same as readf1, but uses the 1line file format.
    std::ifstream holyFile;
    holyFile.open("THE_HOLY_ORDER_x.txt");
    u32 a;
    int b;
    char c;
    //double linesLimit = 5'000'000'000;
    double curLines = 0;
    const int SIZE_OF_ORDER = 82'341'044;
    THE_HOLY_ORDER.reserve(SIZE_OF_ORDER);
    while ((holyFile >> a  >> c >> b >> c) && (c == ',')){
        // pool x;
        // x.blink = b;
        // x.seed = a;
        THE_HOLY_ORDER.emplace_back(b,a);
        // curLines++;
    }
    holyFile.close();
}
void readF3(std::vector<pool>&THE_HOLY_ORDER){
    std::ifstream holyFile;
    holyFile.open("THE_HOLY_ORDER_x.txt");
    const int SIZE_OF_ORDER = 82'341'044;
    THE_HOLY_ORDER.reserve(SIZE_OF_ORDER);
    std::string data = "";
    getline(holyFile,data);
    std::cout << "Read finished!\n";
    std::istringstream ss(data);
    std::cout << "ss finished!";
    holyFile.close();
    std::string token = "";
    while (getline(ss,token,',')){
        u32 seed;
        auto [p, ecSeed] = std::from_chars(token.data(), token.data() + token.size(), seed);
        if (ecSeed == std::errc()) {
            std::getline(ss, token, ',');
            int blink;
            auto [pBlink, ecBlink] = std::from_chars(token.data(), token.data() + token.size(), blink);
            if (ecBlink == std::errc()) {
                THE_HOLY_ORDER.emplace_back(blink, seed);
            } else {
                // Handle conversion error for blink
                std::cerr << "Error converting blink token to integer.\n";
            }
        } else {
            // Handle conversion error for seed
            std::cerr << "Error converting seed token to integer.\n";
        }
    }
    
}

int performSearch(u32 &outSeed, const std::vector<pool>& mainPool, std::vector<int> blinkList){
    if (!mainPool.empty()){
        std::vector<int> resultIndexes = searchPool(mainPool,blinkList,0); //does not persist between searches -- for size(), null == 0
            if (resultIndexes.size() > 1){
                std::cout << resultIndexes.size() <<" results found!";
                return 2;
            } else if (resultIndexes.size() == 1){
                int foundIdx = resultIndexes.front()+blinkList.size()-1;
                outSeed = mainPool[foundIdx].seed;
                std::cout << "SUCCESS: Seed is: 0x" << std::hex << outSeed << std::dec << ". "; 
                // findgap after for verification?
                foundIdx = resultIndexes.front();
                std::cout << "Located at: " << foundIdx;
                //Use debug if necessary
                return 1;
            } else { //Size == 0
                //Failure case
                std::cout << "FAILURE!";
                int foundIdx = -1;
                return 0;
            }

            //RECORD BLINK LIST TO LOG

    }
    return -1; //Error
}


void printPoolVec(std::vector<pool> vpool){
    for (int i = 0; i < 100; i++)
    {
        int spot = i;
        std::cout << std::dec << std::setw(4) << spot << ": " << "(" << vpool.at(i).blink << ", " << std::hex << vpool.at(i).seed << ")\n";
    }
}
std::vector<int> poolToBlinks(std::vector<pool> inPool){
    //prob wrote this somewhere already
    std::vector<int>blinkList;
    for (pool x : inPool){
        blinkList.push_back(x.blink);
    }
    return blinkList;
}


void writeF2(const std::vector<pool>THE_HOLY_ORDER){
    std::ofstream holyFile;
    holyFile.open("THE_HOLY_ORDER_x.txt");
    std::string testStr = "";
    for (int i = 0; i < THE_HOLY_ORDER.size(); i++){
        holyFile << THE_HOLY_ORDER.at(i).seed << "," << THE_HOLY_ORDER.at(i).blink << ",";
        //testStr = testStr + std::to_string(THE_HOLY_ORDER.at(i).seed) + "," + std::to_string(THE_HOLY_ORDER.at(i).blink) + ",";
    }
    holyFile.close();
}
void writeF3(const std::vector<pool>THE_HOLY_ORDER){
    std::ofstream holyFile;
    holyFile.open("THE_HOLY_ORDER_y.txt");
    for (int i = 0; i < THE_HOLY_ORDER.size(); i++){
        holyFile << THE_HOLY_ORDER.at(i).blink << ",";
        //testStr = testStr + std::to_string(THE_HOLY_ORDER.at(i).seed) + "," + std::to_string(THE_HOLY_ORDER.at(i).blink) + ",";
    }
    holyFile.close();
}


std::vector<pool> experimentalRead(){
    std::string buffer;
    
    std::ifstream f("THE_HOLY_ORDER_x.txt");
    f.seekg(0, std::ios::end);
    double length = f.tellg();
    std::cout << "FILE_LENGTH: " << length << "\n";
    buffer.resize(f.tellg());
    f.seekg(0);
    f.read(buffer.data(), buffer.size());
    f.close();
    
    std::cout << "FINISHED READ!";
    // Str size: " << buffer.length() << "\n";
    //Process
    std::istringstream ss(buffer);
    std::string token;
    std::vector<pool>outOrder;
    const int SIZE_OF_ORDER = 82'341'044;
    outOrder.reserve(SIZE_OF_ORDER);
    while(std::getline(ss,token,',')){
        // Directly construct the pool object in the vector
        u32 seed;
        auto [p, ecSeed] = std::from_chars(token.data(), token.data() + token.size(), seed);
        if (ecSeed == std::errc()) {
            std::getline(ss, token, ',');
            int blink;
            auto [pBlink, ecBlink] = std::from_chars(token.data(), token.data() + token.size(), blink);
            if (ecBlink == std::errc()) {
                outOrder.emplace_back(blink, seed);
            } else {
                // Handle conversion error for blink
                std::cerr << "Error converting blink token to integer.\n";
            }
        } else {
            // Handle conversion error for seed
            std::cerr << "Error converting seed token to integer.\n";
        }

        
        // outOrder.emplace_back(static_cast<u32>(std::stoll(token)), 0);
        // std::getline(ss, token, ',');
        // outOrder.back().blink = std::stoi(token);
        
        
        
        
        // pool datum;
        // datum.seed = static_cast<u32>(std::stoll(token));
        // std::getline(ss,token,',');
        // datum.blink = std::stoi(token);
        // outOrder.push_back(datum);


        // std::cout << "i: " << i << "\n";
        // std::cout << "Token:" << token << "\n";


        // pool datum;
        // if (i & 1){
        //     //odd
        //     datum.blink = std::stoi(token);
        //     outOrder.push_back(datum);
        // } else {
        //     //even
        //     //std::cout << "SEED: " << token;
        //     datum.seed = static_cast<u32>(std::stoll(token));

        // }
    }
    return outOrder;
}

std::vector<pool> blinkListToPools(std::vector<int> blinkList, u32 startSeed = 0){
    std::vector<pool>outPool;
    for (int x : blinkList){

    }
    return outPool;
    
}

void experimentalRead2(std::vector<pool>&outOrder){
    std::string buffer;
    
    std::ifstream f("THE_HOLY_ORDER_y.txt");
    f.seekg(0, std::ios::end);
    buffer.resize(f.tellg());
    f.seekg(0);
    f.read(buffer.data(), buffer.size());
    f.close();
    
    std::cout << "FINISHED READ!\n";
    //Process
    std::istringstream ss(buffer);
    buffer.clear();
    buffer.shrink_to_fit();
    std::string token;
    const int SIZE_OF_ORDER = 82'341'044;
    // std::vector<int> orderBlinks;
    // orderBlinks.reserve(SIZE_OF_ORDER);
    outOrder.reserve(SIZE_OF_ORDER);
    while (std::getline(ss, token, ',')) {
        //std::cout << token << std::endl;
        // Directly construct the pool object in the vector
        int blink;
        auto [p, ec] = std::from_chars(token.data(), token.data() + token.size(), blink);
        if (ec == std::errc()) {
            outOrder.emplace_back(blink,0); // Assuming there is another token for blink, but it's set to 0 in the constructor
        } else {
            // Handle conversion error
            std::cerr << "Error converting token to integer.\n";
        }
    }
    ss.str("");
    std::cout << "Finished first list\n";
    outOrder.front().seed = 0xefcb07;
    for (int i = 0; i < outOrder.size()-1; i++){
        u32 nextSeed = outOrder[i].seed;
        LCGn(nextSeed,outOrder[i+1].blink-9);
        outOrder[i+1].seed = nextSeed;
    }
}

void createTheHolyOrder(u32 initSeed,platform plat, std::vector<pool>&THE_HOLY_POOL, double limit){
    u32 seed = initSeed;
    std::cout << "Starting generation!\n";
    THE_HOLY_POOL = generateBlinks(seed,plat,limit); //This last variable expands massively due to limit++ in gen.blinks, need to monitor.
    std::cout << "DONE! Size: ";
    std::cout << THE_HOLY_POOL.size();
}

int main(){


    //Given random input, search the pool at various lengths to determine best size of seeds to take in.
    //Estimating 10, can run a seqtest style scan to prove, gonna just see how punishing it really is. 
    std::string str;
    std::cout << "MAX: " << str.max_size() << "\n";
    u32 seed = 0xDeadbeef;
    platform plat = platform(0,0,NTSCU);

    // double lim = 1000;
    // std::vector<pool> set1 = generateBlinks(seed,plat,lim);
    // set1.erase(set1.begin());
    // std::vector<int> blinkList = poolToBlinks(set1);
    // LCGn_BACK(seed,2000);
    // lim = 25'000;
    // std::vector<pool> set2 = generateBlinks(seed,plat,lim);
    // std::cout << "pool1: \n";
    // printPoolVec(set1);
    // std::cout << "\npool2: \n";
    // printPoolVec(set2);
    // u32 resSeed = 0;
    // performSearch(resSeed,set2,blinkList);

    double lim = 700;
    std::vector<pool> beefpool = generateBlinks(seed,plat,lim);
    u32 normSeed = beefpool.back().seed;
    beefpool = generateBlinks(normSeed,plat,lim);
    beefpool.erase(beefpool.begin());
    //beefpool.erase(beefpool.end()-8,beefpool.end());
    std::vector<int> beefInts = poolToBlinks(beefpool);
    std::cout << "VERIFY SEED: " << std::hex << beefpool.back().seed << std::dec << ". Size: " << beefpool.size();
    std::cout << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);

    std::vector<pool> THE_HOLY_ORDER;


    
    // std::cout << "<BUILD ORDER>";
    //  start = std::chrono::high_resolution_clock::now();
    // createTheHolyOrder(0,plat,THE_HOLY_ORDER,UINT32_MAX);
    //  stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    // std::cout << "VERIFY: " << THE_HOLY_ORDER.size() << " in: " << duration.count() << " seconds.\n";
    // // --- 64 SECONDS TO BEAT.
    
    //LCGn_BACK(seed,5000);
    // LCGn_BACK(normSeed,100'000);
    // std::vector<pool> tpool = generateBlinks(normSeed,plat,100'0000);
    // std::cout << "<READING>";
    // start = std::chrono::high_resolution_clock::now();
    // readF(THE_HOLY_ORDER);
    // stop = std::chrono::high_resolution_clock::now();
    // duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    // std::cout << "VERIFY: " << THE_HOLY_ORDER.size() << " in: " << duration.count() << " seconds.\n";

    // std::cout << "<WRITING>";
    //  start = std::chrono::high_resolution_clock::now();
    // writeF3(THE_HOLY_ORDER);
    //  stop = std::chrono::high_resolution_clock::now();
    //  duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    // std::cout << "WROTE: " << THE_HOLY_ORDER.size() << " in: " << duration.count() << " seconds.\n";


// //   readf normal: 23 seconds to beat. uses extraction operator with delim, not getline.
    // std::cout << "<EXPERIMENTAL READ>";
    //  start = std::chrono::high_resolution_clock::now();
    // THE_HOLY_ORDER = experimentalRead();
    //  stop = std::chrono::high_resolution_clock::now();
    //  duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    // std::cout << "VERIFY: " << THE_HOLY_ORDER.size() << " in: " << duration.count() << " seconds.\n";
    
    std::cout << "<EXPERIMENTAL READ>";
     start = std::chrono::high_resolution_clock::now();
    experimentalRead2(THE_HOLY_ORDER);
     stop = std::chrono::high_resolution_clock::now();
     duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    std::cout << "VERIFY: " << THE_HOLY_ORDER.size() << " in: " << duration.count() << " seconds.\n";
    
    //printPoolVec(THE_HOLY_ORDER);
    //std::cout << "FIRST POOL: {b:" << THE_HOLY_ORDER.front().blink << ", s:" << std::hex << THE_HOLY_ORDER.front().seed << std::dec << "}\n"; 
    
    //Just need to harcode the first and last seeds of the the system, then should be fine.
    // std::cout << "<WRITING>";
    //  start = std::chrono::high_resolution_clock::now();
    // writeF3(THE_HOLY_ORDER);
    //  stop = std::chrono::high_resolution_clock::now();
    //  duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    // std::cout << "WROTE: " << THE_HOLY_ORDER.size() << " in: " << duration.count() << " seconds.\n";


    //printPoolVec(THE_HOLY_ORDER);
    
    // for (int i = 1; i < THE_HOLY_ORDER.size()-1; i++){
    //     int x = findGapConfident(THE_HOLY_ORDER.at(i).seed,THE_HOLY_ORDER.at(i+1).seed);
    //     if (THE_HOLY_ORDER.at(i+1).blink - 9 != x){
    //         std::cout << "FAILED!\n";
    //     }
    // }
    //std::cout << "Complete!";

    u32 resSeed = 0;
    performSearch(resSeed,THE_HOLY_ORDER,beefInts);

    //I really need a time() function. 
    std::cout << "\n<SUM READ>";
     start = std::chrono::high_resolution_clock::now();
    
    int sum = 0;
    for (pool x : THE_HOLY_ORDER){
        sum += x.blink;
    }

     stop = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "VERIFY: " << std::dec << sum << " in: " << duration.count() << " ms.\n";

    
    // std::vector<int> locInts = searchPool(THE_HOLY_ORDER,beefInts,1);
    // if (locInts.size() == 1){
    // std::cout << "LOCATION: " << locInts.front() << ": " << std::hex << THE_HOLY_ORDER[locInts.front()].seed << "\n";
    // } else if(locInts.size() > 1){
    //     std::cout << "MULTIPLE SUCCESSES: ";
    //     for (int x : locInts){
    //         std::cout << x << ":" << std::hex << THE_HOLY_ORDER[x].seed << std::dec << " , ";
    //     }
    // } else {
    //     std::cout << "FAILURE!";
    // }
    


    return 0;
}