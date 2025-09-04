// Solution 1
class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        string ans = "";
        while(i < s.length() && s[i] == ' ') ++i;
        while(i < s.length()) {
            string word = "";
            while(i < s.length() && s[i] != ' ') {
                word += s[i];
                ++i;
            }
            ans = word + " " + ans;
            while(i < s.length() && s[i] == ' ') ++i;
        }

        ans.pop_back();
        return ans;
    }
};

// Solution 2
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, ans = "";

        // Extract words one by one
        while (ss >> word) {
            ans = word + " " + ans;
        }

        // Remove the trailing space
        if (!ans.empty()) ans.pop_back();

        return ans;
    }
};