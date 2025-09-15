// Solution 1
class Solution {
  public:
    string minWindow(string& s, string& t) {
        // Code here
        int n = s.length(), m = t.length();
        int ans = INT_MAX;
        int i = 0, j = 0, k = 0;
        int idx = -1;
        // i iterate on s, k iterate on t and j is to find valid minimal window
        // to find valid window we're iterating backward from i in s and m - 1 in t
        
        while(i < n) {
            if(s[i] == t[k]) k++;
            
            if(k == m) {
                j = i;
                k = m - 1;
                while(k >= 0 && j >= 0) {
                    if(s[j] == t[k]) k--;
                    --j;
                }
                ++j;
                
                if((i - j + 1) < ans) {
                    ans = i - j + 1;
                    idx = j;
                }
                
                i = j;
                k = 0;
            }
            ++i;
        }
        
        if(idx == -1) return "";
        return s.substr(idx, ans);
    }
};

// Solution 2
class Solution {
  public:
  
    bool solve(string &s, string &t, int st, int end) {
        int j = 0;
        for(int i = st; i <= end; ++i) {
            if(s[i] == t[j]) ++j;
            if(j == t.length()) return 1;
        }
        
        return 0;
    }
  
    string minWindow(string& s, string& t) {
        int m = s.length(), n = t.length();
        if(m < n) return "";


        int ans = INT_MAX;;
        int idx = -1;
        int i = 0;
        
        for(int j = 0; j < m; ++j) {

            while(solve(s, t, i, j)) {
                if((j - i + 1) < ans) {
                    idx = i;
                    ans = j - i + 1;
                }
                
                ++i;
            }
        }

        if(idx == -1) return "";
        return s.substr(idx, ans);
    }
};