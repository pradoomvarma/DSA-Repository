class NumArray {
public:

    int n;
    vector<int> segTree;

    void buildSegTree(int i, int l, int r, vector<int>& segTree, vector<int>& nums) {
        if(l == r) {
            segTree[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegTree(2 * i + 1, l, mid, segTree, nums);
        buildSegTree(2 * i + 2, mid + 1, r, segTree, nums);

        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4 * n);
        buildSegTree(0, 0, n - 1, segTree, nums);
    }

    void updateSegTree(int idx, int val, int i, int l, int r, vector<int>& segTree) {
        if(l == r) {
            segTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        if(idx <= mid) updateSegTree(idx, val, 2 * i + 1, l, mid, segTree);
        else updateSegTree(idx, val, 2 * i + 2, mid + 1, r, segTree);

        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }
    
    void update(int index, int val) {
        updateSegTree(index, val, 0, 0, n - 1, segTree);        // Point update in a segment tree
    }

    int querySegTree(int st, int end, int i, int l, int r, vector<int>& segTree) {
        if(l > end || r < st) return 0;

        if(l >= st && r <= end) return segTree[i];
        
        int mid = l + (r - l) / 2;
        return querySegTree(st, end, 2 * i + 1, l, mid, segTree) + querySegTree(st, end, 2 * i + 2, mid + 1, r, segTree);
    }
    
    int sumRange(int left, int right) {
        return querySegTree(left, right, 0, 0, n - 1, segTree);      // Range Query
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */