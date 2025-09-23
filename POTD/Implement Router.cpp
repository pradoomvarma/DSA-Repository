class Router {
public:

    int n;
    queue<string> q;
    unordered_map<string, vector<int>> packetMap;
    unordered_map<int, vector<int>> dstTimeMap;

    Router(int memoryLimit) {
        n = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key = to_string(source) + "_" + to_string(destination) + "_" + to_string(timestamp);

        if(packetMap.find(key) != packetMap.end()) return 0;
        
        if(q.size() >= n) {
            forwardPacket();
        }

        packetMap[key] = {source, destination, timestamp};
        q.push(key);
        dstTimeMap[destination].push_back(timestamp);

        return 1;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};

        string key = q.front();   q.pop();

        vector<int> pkt = packetMap[key];
        packetMap.erase(key);

        int d = pkt[1];
        dstTimeMap[d].erase(dstTimeMap[d].begin());

        return pkt;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = dstTimeMap.find(destination);
        if(it == dstTimeMap.end() || it->second.empty()) return 0;

        vector<int> &timestamps = it->second;
        int i = lower_bound(begin(timestamps), end(timestamps), startTime) - begin(timestamps);
        int j = upper_bound(begin(timestamps), end(timestamps), endTime) - begin(timestamps);

        return j - i;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */