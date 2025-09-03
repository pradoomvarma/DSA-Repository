class Solution {
  public:
  
    int solve(vector<int> &arr, int k, int mid) {
        int stud = 1;
        int page = 0;
        
        for(auto el : arr) {
            page += el;
            if(page > mid) {
                stud++;
                page = el;
            }
        }
        
        return stud;
    }
  
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k > n) return -1;
        
        int s = *max_element(begin(arr), end(arr));
        int e = accumulate(begin(arr), end(arr), 0);
        
        while(s <= e) {
            int mid = s + (e - s) / 2;
            int stud = solve(arr, k, mid);
            
            if(stud > k) s = mid + 1;
            else e = mid - 1;
        }
        
        return s;
    }
};