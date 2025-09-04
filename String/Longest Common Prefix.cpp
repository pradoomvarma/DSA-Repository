class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        
        for(int i = 0; i < strs[0].length(); ++i) {
            char ch = strs[0][i];
            bool f = 1;
            for(int j = 1; j < strs.size(); ++j) {
                if(strs[j][i] != ch) {
                    f = 0;
                    break;
                }
            }
            if(!f) break;
            ans += ch;
        }

        return ans;
    }
};