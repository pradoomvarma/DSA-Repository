// Approach 1
class Solution {
public:

    void buildSegTree(int i, int l, int r, vector<int> &segTree, vector<int> &baskets) {
        if(l == r) {
            segTree[i] = l;     // stores index
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegTree(2 * i + 1, l, mid, segTree, baskets);
        buildSegTree(2 * i + 2, mid + 1, r, segTree, baskets);

        // store the index of maximum element
        int leftMaxIdx = segTree[2 * i + 1];
        int rightMaxIdx = segTree[2 * i + 2];

        if(baskets[leftMaxIdx] >= baskets[rightMaxIdx]) segTree[i] = leftMaxIdx;
        else segTree[i] = rightMaxIdx;
    }

    // This returns the index of maximum element in range [st, end] in heights
    int Query(int st, int end, int i, int l, int r, vector<int> &segTree, vector<int> &baskets) {
        if(l > end || r < st) return -1;
        if(l >= st && r <= end) return segTree[i];

        int mid = l + (r - l) / 2;
        int leftMaxIdx = Query(st, end, 2 * i + 1, l, mid, segTree, baskets);
        int rightMaxIdx = Query(st, end, 2 * i + 2, mid + 1, r, segTree, baskets);
        if(leftMaxIdx == -1) return rightMaxIdx;
        if(rightMaxIdx == -1) return leftMaxIdx;

        if(baskets[leftMaxIdx] >= baskets[rightMaxIdx]) return leftMaxIdx;
        return rightMaxIdx;
    }

    void updateSegTree(int idx, int val, int i, int l, int r, vector<int> &segTree, vector<int> &baskets) {
        if(l == r) {
            baskets[idx] = val;
            segTree[i] = l;
            return;
        }

        int mid = l + (r - l) / 2;
        if(idx <= mid) updateSegTree(idx, val, 2 * i + 1, l, mid, segTree, baskets);
        else updateSegTree(idx, val, 2 * i + 2, mid + 1, r, segTree, baskets);

        int leftIdx = segTree[2 * i + 1];
        int rightIdx = segTree[2 * i + 2];
        segTree[i] = (baskets[leftIdx] >= baskets[rightIdx]) ? leftIdx : rightIdx;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int> segTree(4 * n);
        buildSegTree(0, 0, n - 1, segTree, baskets);    // O(n)

        int ans = 0;
        for(int i = 0; i < n; ++i) {    // O(q)
            int res = n;
            int l = 0;
            int r = n - 1;

            while(l <= r) {     // O(logn)
                int mid = l + (r - l) / 2;
                int idx = Query(l, mid, 0, 0, n - 1, segTree, baskets); 

                if(idx != -1 && baskets[idx] >= fruits[i]) {
                    res = min(res, idx);
                    r = mid - 1;
                }
                else l = mid + 1;
            }

            if(res != n) {
                updateSegTree(res, 0, 0, 0, n - 1, segTree, baskets);
            }
            else ans++;
        }

        return ans;
    }
};

// Approach 2
class Solution {
public:

    void buildSegmentTree(int i, int l, int r, vector<int> &segTree, vector<int> &baskets) {
        if(l == r) {
            segTree[i] = baskets[l];
            return;
        }
        
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, segTree, baskets);
        buildSegmentTree(2 * i + 2, mid + 1, r, segTree, baskets);
        
        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    bool Query(int i, int l, int r, vector<int> &segTree, int fruit) {
        if(segTree[i] < fruit) return 0;

        if(l == r) {
            segTree[i] = -1;    // mark it & assign fruit in this basket
            return 1;
        }

        int mid = l + (r - l) / 2;
        bool placed = 0;

        if(segTree[2 * i + 1] >= fruit) {
            placed = Query(2 * i + 1, l, mid, segTree, fruit);
        }
        else {
            placed = Query(2 * i + 2, mid + 1, r, segTree, fruit);
        }

        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int> segTree(4 * n);
        buildSegmentTree(0, 0, n - 1, segTree, baskets);

        int cnt = 0;
        for(auto &f : fruits) {     // O(M)
            if(!Query(0, 0, n - 1, segTree, f)) cnt++;  // O(logN)
        }

        // TC = O(MlogN)    SC = O(N)
        return cnt;
    }
};