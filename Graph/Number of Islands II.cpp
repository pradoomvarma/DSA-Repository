#include <bits/stdc++.h>

class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void Union(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	// Write your code here.
	DisjointSet ds(n * m + 1);
    vector<vector<int>> vis(n, vector<int> (m, 0));

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    vector<int> ans;
    int cnt = 0;

    for(auto it : q) {
        int i = it[0];
        int j = it[1];

        if(vis[i][j]) {
            ans.push_back(cnt);
            continue;
        }

        vis[i][j] = 1;
        cnt++;

        int u = i * m + j;

        for(int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni >= 0 && ni < n && nj >= 0 && nj < m && vis[ni][nj] == 1) {
                int v = ni * m + nj;
            
                if(ds.findPar(u) != ds.findPar(v)) {
                    ds.Union(u, v);
                    cnt--;
                }
            }
        }

        ans.push_back(cnt);
    }

    return ans;
}