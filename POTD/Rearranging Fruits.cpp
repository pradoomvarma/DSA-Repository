class Solution {
public:

    typedef long long ll;

    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<ll, ll> mp;
        
        for(auto el : basket1) {
            mp[el]++;
        }

        for(auto el : basket2) {
            mp[el]++;
        }

        ll minVal = LLONG_MAX;
        for(auto it : mp) {
            if(it.second % 2 == 1) return -1;
            minVal = min(minVal, it.first);
        }

        vector<ll> arr;
        map<ll, ll> mp1;
        for(auto el : basket1) {
            mp1[el]++;
        }

        for(auto it : mp) {
            int cnt = abs(mp1[it.first] - (it.second / 2));
            while(cnt--) {
                arr.push_back(it.first);
            }
        }

        sort(begin(arr), end(arr));
        ll cnt = arr.size() / 2;
        ll ans = 0, i = 0;

        for(int i = 0; i < cnt; ++i) {
            ans += min(arr[i], 2 * minVal);
        }
        
        return ans;
    }
};