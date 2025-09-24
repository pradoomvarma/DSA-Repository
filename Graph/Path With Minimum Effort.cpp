class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> pathEffort(n, vector<int> (m, 1e9));

        pq.push({0, {0, 0}});
        pathEffort[0][0] = 0;

        while(!pq.empty()) {
            auto cell = pq.top();  pq.pop();
            int currEffort = cell.first;
            int x = cell.second.first;
            int y = cell.second.second;

            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int diff = abs(heights[x][y] - heights[nx][ny]);
                    int newEffort = max(currEffort, diff);

                    if(newEffort < pathEffort[nx][ny]) {
                        pathEffort[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
        }

        return pathEffort[n - 1][m - 1];
    }
};