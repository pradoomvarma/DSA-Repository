class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mp[256] = {0};
        int n = s.length();
        int ans = 0;
        int i = 0;

        for(int j = 0; j < n; ++j) {
            mp[s[j]]++;

            while(mp[s[j]] > 1) {
                mp[s[i]]--;
                ++i;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};