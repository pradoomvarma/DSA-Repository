
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> ans;
        int n = arr.size();
        int maxi = arr[n - 1];
        
        for(int i = n - 1; i >= 0; --i) {
            maxi = max(maxi, arr[i]);
            if(maxi == arr[i]) ans.push_back(arr[i]);
        }
        
        reverse(begin(ans), end(ans));
        return ans;
    }
};