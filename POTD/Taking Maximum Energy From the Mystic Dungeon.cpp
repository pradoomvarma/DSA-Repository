class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < energy.size(); ++i) {
            mp[i % k].push_back(energy[i]);
        } 

        int ans = INT_MIN;
        for(auto it : mp) {
            int sum = 0;
            auto vec = it.second;
            int n = vec.size();
            for(int i = n - 1; i >= 0; --i) {
                sum += vec[i];
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};