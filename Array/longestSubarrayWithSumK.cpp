class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> mp;
        mp[0] = -1;
        int ans = 0;
        int sum = 0;
        
        for(int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            int rem = sum - k;   // total is 'sum' and current is 'k' then to find in past remaining is (sum - k)
            
            if(mp.find(rem) != mp.end()) {
                int len = i - mp[rem];
                ans = max(ans, len);
            }
            
            if(mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }
        
        return ans;
    }
};