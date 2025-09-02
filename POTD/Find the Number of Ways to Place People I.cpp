// Solution 1
class Solution {
public:

    int solve(vector<vector<int>>& points, int i, int j) {
        int x1 = points[i][0];
        int y1 = points[i][1];

        int x2 = points[j][0];
        int y2 = points[j][1];

        if(x1 > x2 || y1 < y2) return 0;

        for(int k = 0; k < points.size(); ++k) {
            if(k == i || k == j) continue;
            int x = points[k][0];
            int y = points[k][1];
            if((x1 <= x && x <= x2) && (y2 <= y && y <= y1)) return 0;
        }

        return 1;
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == j) continue;
                int temp = solve(points, i, j);
                if(temp) ans++;
            }
        }

        return ans;
    }
};