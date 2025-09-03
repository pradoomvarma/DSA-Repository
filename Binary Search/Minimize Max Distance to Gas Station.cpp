// Solution 1 : Brute Force
class Solution {
  public:
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        if(n == 1) return 0.00;
        
        vector<int> howMany(n - 1, 0);
        
        for(int gasStation = 1; gasStation <= k; ++gasStation) {
            long double maxSection = -1;
            int maxIdx = -1;
            for(int i = 0; i < n - 1; ++i) {
                long double diff = stations[i + 1] - stations[i];
                long double sectionLen = diff / (long double)(howMany[i] + 1);
                if(maxSection < sectionLen) {
                    maxSection = sectionLen;
                    maxIdx = i;
                }
            }
            howMany[maxIdx]++;
        }
        
        long double maxAns = -1;
        for(int i = 0; i < n - 1; ++i) {
            long double diff = stations[i + 1] - stations[i];
            long double sectionLen = diff / (long double)(howMany[i] + 1);
            maxAns = max(maxAns, sectionLen);
        }
        
        return maxAns;
    }
};

// Solution 2: Heap
class Solution {
  public:
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        if(n == 1) return 0.00;
        
        vector<int> howMany(n - 1, 0);
        priority_queue<pair<long double, int>> pq;
        
        for(int i = 0; i < n - 1; ++i) {
                long double diff = stations[i + 1] - stations[i];
                pq.push({diff, i});
            }
        
        for(int gasStation = 1; gasStation <= k; ++gasStation) {
            auto [diff, secIdx] = pq.top();    pq.pop();
            howMany[secIdx]++;
            long double newDiff = (stations[secIdx + 1] - stations[secIdx]) / (long double)(howMany[secIdx] + 1);
            pq.push({newDiff, secIdx});
        }
        
        return pq.top().first;
    }
};

// Solution 3: Binary Search
class Solution {
  public:
  
    int solve(vector<int> &arr, long double dist) {
        int cnt = 0;
        
        for(int i = 1; i < arr.size(); ++i) {
            int numInBtw = (arr[i] - arr[i - 1]) / dist;
            if((arr[i] - arr[i - 1]) / dist == numInBtw + dist) numInBtw--;
            cnt += numInBtw;
        }
        
        return cnt;
    }
  
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        
        long double st = 0.0, end = 0.0;
        
        for(int i = 1; i < n; ++i) {
            long double diff = stations[i] - stations[i - 1];
            end = max(end, diff);
        }
        
        long double diff = 1e-6;
        while(end - st > diff) {
            long double mid = (st + end) / 2.0;
            int cnt = solve(stations, mid);
            if(cnt > k) st = mid;
            else end = mid;
        }
        
        return end;
    }
}; 