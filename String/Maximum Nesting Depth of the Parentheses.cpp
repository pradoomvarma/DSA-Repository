class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int maxi = 0;

        for(auto ch : s) {
            if(ch == '(') cnt++;
            else if(ch == ')') cnt--;
            maxi = max(maxi, cnt);
        }

        return maxi;
    }
};