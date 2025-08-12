class Solution {
public:
    
    void buildSegTree(int i, int l, int r, vector<int> &segTree, vector<int> &heights) {
        if(l == r) {
            segTree[i] = l;     // stores index
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegTree(2 * i + 1, l, mid, segTree, heights);
        buildSegTree(2 * i + 2, mid + 1, r, segTree, heights);

        // store the index of maximum element
        int leftMaxIdx = segTree[2 * i + 1];
        int rightMaxIdx = segTree[2 * i + 2];

        if(heights[leftMaxIdx] >= heights[rightMaxIdx]) segTree[i] = leftMaxIdx;
        else segTree[i] = rightMaxIdx;
    }

    // This returns the index of maximum element in range [st, end] in heights
    int Query(int st, int end, int i, int l, int r, vector<int> &segTree, vector<int> &heights) {
        if(l > end || r < st) return -1;
        if(l >= st && r <= end) return segTree[i];

        int mid = l + (r - l) / 2;
        int leftMaxIdx = Query(st, end, 2 * i + 1, l, mid, segTree, heights);
        int rightMaxIdx = Query(st, end, 2 * i + 2, mid + 1, r, segTree, heights);
        if(leftMaxIdx == -1) return rightMaxIdx;
        if(rightMaxIdx == -1) return leftMaxIdx;

        if(heights[leftMaxIdx] >= heights[rightMaxIdx]) return leftMaxIdx;
        return rightMaxIdx;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> segTree(4 * n);
        buildSegTree(0, 0, n - 1, segTree, heights);    // O(n)

        vector<int> ans;
        for(auto &q : queries) {    // O(q)
            int st = q[0];
            int end = q[1];
            int maxIdx = max(st, end);
            int minIdx = min(st, end);
            
            if(minIdx == maxIdx) ans.push_back(minIdx);
            else if(heights[minIdx] < heights[maxIdx]) ans.push_back(maxIdx);
            else {
                int res = n;
                int l = maxIdx + 1;
                int r = n - 1;

                while(l <= r) {     // O(logn)
                    int mid = l + (r - l) / 2;
                    int idx = Query(l, mid, 0, 0, n - 1, segTree, heights); // returns max elem ka Idx in range [l, mid] || // O(logn)

                    if(idx != -1 && heights[idx] > max(heights[st], heights[end])) {
                        res = min(res, idx);
                        r = mid - 1;
                    }
                    else l = mid + 1;
                }

                if(res == n) ans.push_back(-1);
                else ans.push_back(res);
            }
        }

        // TC = O(Q * (logN)^2)
        // SC = O(N)
        return ans;
    }
};