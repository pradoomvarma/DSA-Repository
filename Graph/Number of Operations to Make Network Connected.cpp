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

        if(size[u] < size[v]) {
            parent[upar] = vpar;
            size[v] += size[u];
        }
        else {
            parent[vpar] = upar;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int extraEdges = 0;
        for(auto it : connections) {
            int u = it[0];
            int v = it[1];

            if(ds.findPar(u) != ds.findPar(v)) {
                ds.Union(u, v);
            }
            else extraEdges++;
        }

        int comp = 0;
        for(int i = 0; i < n; ++i) {
            if(ds.findPar(i) == i) comp++;
        }

        if(extraEdges < comp - 1) return -1;
        return comp - 1;
    }
};