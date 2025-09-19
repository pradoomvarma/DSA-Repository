class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        vector<vector<int>> dist(m, vector<int> (n, 1e9));

        queue<pair<int, pair<int, int>>> q;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(mat[i][j] == 0) {
                    q.push({0, {i, j}});
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto f = q.front();     q.pop();
                int d = f.first;
                int x = f.second.first;
                int y = f.second.second;

                for(int i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && (d + 1 < dist[nx][ny])) {
                        dist[nx][ny] = d + 1;
                        q.push({d + 1, {nx, ny}});
                    }
                }
            }
        }

        return dist;
    }
};