class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);  // apply bs on smaller part for efficiency

        int st = 0, end = m;    // binary search on how much elem we can pick from left side
        int left = (m + n + 1) / 2; // how much should be there on left side if combined both

        while(st <= end) {
            int mid1 = st + (end - st) / 2; // pick mid1 elem from nums1
            int mid2 = left - mid1;     // pick remaining from nums2 to complete left part

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(mid1 < m) r1 = nums1[mid1];
            if(mid2 < n) r2 = nums2[mid2];
            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            if((l1 <= r2) && (l2 <= r1)) {
                if((m + n) % 2 == 0) {
                    // even
                    return ((double)max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else {
                    // odd
                    return max(l1, l2);
                }
            }
            else if(l2 > r1) st = mid1 + 1;
            else end = mid1 - 1;
        }

        return 0.0;
    }
};