class Solution {
public:
    const long long MOD = 1e9 + 7;

    void buildSegmentTree(int i, int l, int r, vector<long long>& segTree, vector<long long>& arr) {
        if (l == r) {
            segTree[i] = arr[l] % MOD;
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, segTree, arr);
        buildSegmentTree(2 * i + 2, mid + 1, r, segTree, arr);

        segTree[i] = (segTree[2 * i + 1] * segTree[2 * i + 2]) % MOD;
    }

    long long Query(int st, int end, int i, int l, int r, vector<long long>& segTree) {
        if (l > end || r < st) return 1; // neutral element for multiplication
        if (l >= st && r <= end) return segTree[i];
        
        int mid = l + (r - l) / 2;
        long long leftProd = Query(st, end, 2 * i + 1, l, mid, segTree);
        long long rightProd = Query(st, end, 2 * i + 2, mid + 1, r, segTree);
        
        return (leftProd * rightProd) % MOD;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> arr;
        for (int i = 0; i < 32; ++i) {
            if ((n >> i) & 1) arr.push_back((1LL << i) % MOD);  
        }

        int sz = arr.size();
        vector<long long> segTree(4 * sz);
        buildSegmentTree(0, 0, sz - 1, segTree, arr);

        vector<int> ans;
        for (auto &q : queries) {
            ans.push_back(Query(q[0], q[1], 0, 0, sz - 1, segTree) % MOD);
        }
        return ans;
    }
};