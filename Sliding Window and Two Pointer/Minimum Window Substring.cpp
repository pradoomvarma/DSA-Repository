// Solution 1

class Solution {
public:

    bool solve(vector<int> mps, vector<int> mpt) {
        for(int i = 0; i < 256; ++i) {
            if(mpt[i] > 0 && mpt[i] > mps[i]) return 0;
        }
        return 1;
    }

    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if(m < n) return "";

        vector<int> mps(256, 0), mpt(256, 0);

        for(auto it : t) mpt[it]++;

        int ans = INT_MAX;;
        int idx = -1;
        int i = 0;
        for(int j = 0; j < m; ++j) {
            mps[s[j]]++;

            while(solve(mps, mpt)) {
                if((j - i + 1) < ans) {
                    idx = i;
                    ans = j - i + 1;
                }
                mps[s[i]]--;
                ++i;
            }
        }

        if(idx == -1) return "";
        return s.substr(idx, ans);
    }
};



// Solution 2
class Solution {
public:

    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if(m < n) return "";

        vector<int> mp(256, 0);

        for(auto ch : t) mp[ch]++;

        int ans = INT_MAX;;
        int idx = -1;
        int i = 0;
        int cnt = 0;

        for(int j = 0; j < m; ++j) {
            if(mp[s[j]] > 0) cnt++;
            mp[s[j]]--;

            while(cnt >= n) {
                if((j - i + 1) < ans) {
                    idx = i;
                    ans = j - i + 1;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0) cnt--;
                ++i;
            }
        }

        if(idx == -1) return "";
        return s.substr(idx, ans);
    }
};