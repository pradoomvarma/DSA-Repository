class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m) return 0;

        int mp[256] = {0};
        int f[256] = {0};

        for(int i = 0; i < n; ++i) {
            if(mp[s[i]] == 0 && f[t[i]] == 0) {
                mp[s[i]] = t[i];
                f[t[i]] = 1;
            }
            else if(mp[s[i]] != t[i]) return 0;
        }

        return 1;
    }
};