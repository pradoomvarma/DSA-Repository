class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0;
        
        int x = 0;
        for(auto el : arr) {
            x ^= el;
            int rem = x ^ k;
            
            if(mp.find(rem) != mp.end()) {
                cnt += mp[rem];
            }
            
            mp[x]++;
        }
        
        return cnt;
    }
};