struct PairHash {
    size_t operator()(const pair<string, string>& p) const {
        // Hash each part of the pair
        size_t h1 = hash<string>()(p.first);
        size_t h2 = hash<string>()(p.second);

        // Combine the two hashes into one
        return h1 ^ (h2 << 1);  // XOR + bit-shift
    }
};


class UndergroundSystem {
    unordered_map<int, pair<string, int>>mpId;
    // map<pair<string, string>, pair<double, double>>mpTime;
    unordered_map<pair<string,string>, pair<double,double>, PairHash> mpTime;
    // vector<vector<pair<int, int>>>arr(11, vector<int>(11));
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mpId[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string strtSt = mpId[id].first;
        int strtTime = mpId[id].second;
        mpTime[{strtSt, stationName}].first += (t-strtTime);
        mpTime[{strtSt, stationName}].second += 1;
        mpId.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (mpTime[{startStation, endStation}].first) / (mpTime[{startStation, endStation}].second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */