class DisjointSet {
    public:
    
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);

        for(int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int u) {
        if(u == parent[u]) return u;

        return parent[u] = findPar(parent[u]);
    }

    void Union(int u, int v) {
        int upar = findPar(u);
        int vpar = findPar(v);

        if(upar == vpar) return;

        if (size[upar] < size[vpar]) {
            parent[upar] = vpar;
            size[vpar] += size[upar];
        } else {
            parent[vpar] = upar;
            size[upar] += size[vpar];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int m = -1, n = -1;
        for(auto it : stones) {
            n = max(n, it[0]);
            m = max(m, it[1]);
        }

        DisjointSet ds(n + m + 2);
        
        unordered_map<int, int> stoneNodes;
        for(auto it : stones) {
            int row = it[0];
            int col = it[1] + n + 1;

            ds.Union(row, col);
            stoneNodes[row] = 1;
            stoneNodes[col] = 1;
        }

        int comp = 0;
        for(auto it : stoneNodes) {
            if(ds.findPar(it.first) == it.first) comp++;
        }
        
        return stones.size() - comp;
    }
};