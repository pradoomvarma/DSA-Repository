class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n1 = a.size();
        int n2 = b.size();
        if(n1 > n2) return kthElement(b, a, k);
        
        int n = n1 + n2;
        int st = max(0, k - n2);    // if k > n1 then if we pick all elem from arr2, we still need (k - n1) that we neeed to pick from arr1
        int end = min(k, n1);   // we want to pick max k for left part so that we can get answer
        int left = k;
        
        while(st <= end) {
            int mid1 = (st + end) >> 1;
            int mid2 = left - mid1;
            
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            
            if(mid1 < n1) r1 = a[mid1];
            if(mid2 < n2) r2 = b[mid2];
            if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = b[mid2 - 1];
            
            if(l1 <= r2 && l2 <= r1) return max(l1, l2);
            else if(l2 > r1) st = mid1 + 1;
            else end = mid1 - 1;
        }
        
        return -1;
    }
};