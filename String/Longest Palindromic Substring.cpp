class Solution {
public:

    string solve(string s, int i, int j) {
        string ans = "";

        while(i >= 0 && j < s.length()) {
            if(s[i] != s[j]) break;
            --i, ++j;
        }

        return s.substr(i + 1, j - i - 1);
    }

    string longestPalindrome(string s) {
        string ans = "";
        int n = s.length();

        for(int i = 0; i < n; ++i) {
            string curr = solve(s, i, i);
            if(curr.length() > ans.length()) {
                ans = curr;
            }
            curr = solve(s, i, i + 1);
            if(curr.length() > ans.length()) {
                ans = curr;
            }
        }

        return ans;
    }
};