class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        
        int n = intervals.size();
        int st = intervals[0][0];
        int end = intervals[0][1];

        vector<vector<int>> ans;

        for(int i = 1; i < n; ++i) {
            if(intervals[i][0] <= end) {
                st = min(st, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
            else {
                ans.push_back({st, end});
                st = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({st, end});
        return ans;
    }
};