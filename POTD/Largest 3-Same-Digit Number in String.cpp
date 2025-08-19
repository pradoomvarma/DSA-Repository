class Solution {
public:
    string largestGoodInteger(string num) {
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int n = num.size();

        while(j < 3 && j < n) {
            mp[num[j]]++;
            ++j;
        }

        string ans = "";
        if(mp.size() == 1) ans = num.substr(i, 3);

        while(j < n) {
            mp[num[j]]++;
            
            while(j - i + 1 > 3) {
                mp[num[i]]--;
                if(mp[num[i]] == 0) mp.erase(num[i]);
                ++i;
            }
            
            if(mp.size() == 1) {
                string temp = num.substr(i, 3);
                if(temp > ans) ans = temp;
            }
            ++j;
        }

        return ans;
    }
};