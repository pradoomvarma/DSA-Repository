class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n & 1)  {
            ans.push_back(0);
            n--;
        }
        int i = 1, cnt = 0;
        while(cnt < n) {
            ans.push_back(i);
            ans.push_back(-i);
            cnt += 2;
            ++i;
        }

        return ans;
    }
};