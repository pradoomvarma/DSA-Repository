class Solution {
public:

    typedef long long ll;

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(begin(potions), end(potions));
        ll n = potions.size();
        vector<int> ans;

        for(ll i = 0; i < spells.size(); ++i) {
            ll val = (spells[i] + success - 1) / spells[i];

            ll idx = lower_bound(begin(potions), end(potions), val) - potions.begin();
            ans.push_back(n - idx);
        }

        return ans;
    }
};