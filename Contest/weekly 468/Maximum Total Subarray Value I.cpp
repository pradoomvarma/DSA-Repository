class Solution {
public:

    typedef long long ll;
    
    long long maxTotalValue(vector<int>& nums, int k) {
        ll maxi = -1e9, mini = 1e9;
        ll ans = 0;

        for(auto el : nums) {
            if(el > maxi) maxi = el;
            if(el < mini) mini = el;
            ll curr = (maxi - mini) * k;
            ans = max(ans, curr);
        }

        return ans;
    }
};