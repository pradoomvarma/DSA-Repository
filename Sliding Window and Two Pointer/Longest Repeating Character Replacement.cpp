class Solution {
public:

    int characterReplacement(string s, int k) {
        int n = s.length();
        int i = 0;
        int ans = 0;
        vector<int> hash(26, 0);
        int maxi = 0;

        for(int j = 0; j < n; ++j) {
            hash[s[j] - 'A']++;
            maxi = max(maxi, hash[s[j] - 'A']);

            while((j - i + 1) - maxi > k) {
                hash[s[i] - 'A']--;
                ++i;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};