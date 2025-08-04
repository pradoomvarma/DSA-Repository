class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int i = 0, maxi = 0;
        
        for(int j = 0; j < fruits.size(); ++j) {
            mp[fruits[j]]++;

            while(i <= j && mp.size() > 2) {
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                ++i;
            }

            maxi = max(maxi, j - i + 1);
        }

        return maxi;
    }
};