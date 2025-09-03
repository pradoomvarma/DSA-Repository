class Solution {
  public:
      
    bool solve(vector<int> &stalls, int k, int dist) {
        int cnt = 1;
        int last = stalls[0];
        
        for(int i = 1; i < stalls.size(); ++i) {
            if((stalls[i] - last) >= dist) {
                cnt++;
                last = stalls[i];
            }
            
            if(cnt >= k) return 1;
        }
        
        return cnt >= k;
    }
        
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(begin(stalls), end(stalls));
        int n = stalls.size();
        int s = 0, e = stalls[n - 1] - stalls[0];
        int ans = -1;
        
        while(s <= e) {
            int mid = s + (e - s) / 2;
            
            if(solve(stalls, k, mid)) {
                ans = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        
        return ans;
    }
};