// only start counting if its starting point of consecutive element

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));
        int maxi = 0;

        for(auto el : st) {
            int cnt = 1;
            if(st.count(el - 1) > 0) continue;
            int v = el + 1;
            while(st.count(v) > 0) {
                cnt++;
                v++;
            }
            maxi = max(maxi, cnt);
        }

        return maxi;
    }
};
