class Solution {
public:

    vector<int> nums;
    vector<int> segMin, segMax;
    int n;

    void build(int i, int l, int r) {
        if(l == r) {
            segMin[i] = segMax[i] = nums[l];
            return;
        }

        int mid = (l + r) / 2;
        build(2*i+1, l, mid);
        build(2*i+2, mid+1, r);

        segMin[i] = min(segMin[2*i+1], segMin[2*i+2]);
        segMax[i] = max(segMax[2*i+1], segMax[2*i+2]);
    }

    int queryMin(int i, int l, int r, int st, int end) {
        if(end < l || r < st) return INT_MAX;
        if(st <= l && r <= end) return segMin[i];

        int mid = (l + r) / 2;
        return min(queryMin(2 * i + 1, l, mid, st, end), queryMin(2 * i + 2, mid + 1, r, st, end));
    }

    int queryMax(int i, int l, int r, int st, int end) {
        if(end < l || r < st) return INT_MIN;
        if(st <= l && r <= end) return segMax[i];
        
        int mid = (l + r) / 2;
        return max(queryMax(2 * i + 1, l, mid, st, end), queryMax(2 * i + 2, mid + 1, r, st, end));
    }

    long long maxTotalValue(vector<int>& arr, int k) {
        nums = arr;
        n = nums.size();
        segMin.resize(4*n);
        segMax.resize(4*n);

        build(0, 0, n-1);

        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int,int>> vis;

        int val = queryMax(0, 0, n - 1, 0, n - 1) - queryMin(0, 0, n - 1, 0, n - 1);
        pq.push({val, {0, n-1}});
        vis.insert({0, n-1});

        long long ans = 0;
        while(k-- && !pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int val = curr.first;
            int l = curr.second.first;
            int r = curr.second.second;

            ans += val;
            if(l == r) continue;

            // Shrink left
            if(l + 1 <= r && !vis.count({l + 1, r})) {
                int valL = queryMax(0, 0, n - 1, l + 1, r) - queryMin(0, 0, n - 1, l + 1, r);
                pq.push({valL, {l + 1, r}});
                vis.insert({l + 1, r});
            }

            // Shrink right
            if(l <= r - 1 && !vis.count({l, r - 1})) {
                int valR = queryMax(0, 0, n - 1, l, r - 1) - queryMin(0, 0, n - 1, l, r - 1);
                pq.push({valR, {l, r - 1}});
                vis.insert({l,r - 1});
            }
        }

        return ans;
    }
};