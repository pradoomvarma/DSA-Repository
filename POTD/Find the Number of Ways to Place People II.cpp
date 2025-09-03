class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(begin(points), end(points), [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) return a[1] >= b[1];
            return a[0] <= b[0];
        });

        int n = points.size();
        int ans = 0;

        for(int i = 0; i < n; ++i) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            int maxY = INT_MIN;
            for(int j = i + 1; j < n; ++j) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(y1 < y2) continue;

                if(y2 > maxY) {
                    ans++;
                    maxY = y2;
                }
            }
        }

        return ans;
    }
};