class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        int target = image[sr][sc];
        image[sr][sc] = color;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;

        while(!q.empty()) {
            auto [x, y] = q.front();    q.pop();
            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] == target && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }

        return image;
    }
};