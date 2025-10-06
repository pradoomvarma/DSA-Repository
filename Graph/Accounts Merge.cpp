class DisjointSet {

    vector<int> parent, size;

    public:

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int node) {
        if (node == parent[node]) return node;

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

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> mp1;
        for(int i = 0; i < n; ++i) {
            for(int j = 1; j < accounts[i].size(); ++j) {
                string mail = accounts[i][j];
                if(mp1.find(mail) == mp1.end()) {
                    mp1[mail] = i;
                }
                else {
                    int par = mp1[mail];
                    int upar = ds.findPar(par);
                    ds.Union(i, upar);
                }
            }
        }

        unordered_map<int, set<string>> mp2;
        for(auto it : mp1) {
            int upar = ds.findPar(it.second);
            mp2[upar].insert(it.first);
        }

        vector<vector<string>> ans;
        for(auto it : mp2) {
            string name = accounts[it.first][0];
            vector<string> temp;
            temp.push_back(name);

            for(auto mail : it.second) temp.push_back(mail);

            ans.push_back(temp);
        }

        return ans;
    }
};