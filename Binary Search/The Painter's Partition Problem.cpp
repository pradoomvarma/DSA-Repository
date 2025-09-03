class Solution {
  public:
  
    int solve(vector<int> &arr, int k, int mid) {
        int painter = 1;
        int sum = 0;
        
        for(auto el : arr) {
            sum += el;
            if(sum > mid) {
                painter++;
                sum = el;
            }
        }
        
        return painter;
    }
  
    int minTime(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        if(k > n) return -1;
        
        int s = *max_element(begin(arr), end(arr));
        int e = accumulate(begin(arr), end(arr), 0);
        
        while(s <= e) {
            int mid = s + (e - s) / 2;
            int painter = solve(arr, k, mid);
            
            if(painter > k) s = mid + 1;
            else e = mid - 1;
        }
        
        return s;
    }
};