// User function Template for C++

class Solution {
  public:
  
    void buildSegmentTree(int i, int l, int r, vector<int>& segTree, int arr[]) {
        if(l == r) {
            segTree[i] = arr[l];
            return;
        }
        
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, segTree, arr);
        buildSegmentTree(2 * i + 2, mid + 1, r, segTree, arr);
        
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }
    
    int Query(int st, int end, int i, int l, int r, vector<int>& segTree) {
        if(l > end || r < st) return 0;
        if(l >= st && r <= end) return segTree[i];
        int mid = l + (r - l) / 2;
        return Query(st, end, 2 * i + 1, l, mid, segTree) + Query(st, end, 2 * i + 2, mid + 1, r, segTree);
    }
  
    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        // code here
        vector<int> segTree(4 * n);
        
        buildSegmentTree(0, 0, n - 1, segTree, arr);
        
        vector<int> ans;
        for(int i = 0; i < 2 * q; i += 2) {
            int st = queries[i] - 1;
            int end = queries[i + 1] - 1;
            
            ans.push_back(Query(st, end, 0, 0, n - 1, segTree));
        }
        
        return ans;
    }
};