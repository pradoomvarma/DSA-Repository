// Solution 1
class Solution {
public:

    long long solve(string s) {
        unordered_map<char, int> mp;
        int n = s.length();
        int i = 0;
        long long ans = 0;

        for(int j = 0; j < n; ++j) {
            mp[s[j]]++;

            while(mp.size() == 3) {
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                ++i;
            }

            ans += (j - i + 1);
        }
        
        return ans + 1;
    }

    int numberOfSubstrings(string s) {
        long long n = s.length();
        long long total = (n * (n + 1) / 2) + 1;
        long long notValid = solve(s);
        return total - notValid;
    }
};

// Solution 2
class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp = {{'a', 0}, {'b', 0}, {'c', 0}};
        int cnt = 0;
        int i = 0;
        int n = s.length();

        for(int j = 0; j < n; ++j) {
            mp[s[j]]++;

            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                cnt += n - j;
                mp[s[i]]--;
                ++i;
            }
        }

        return cnt;
    }
};