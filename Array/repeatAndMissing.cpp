class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int i = 0;
        while(i < arr.size()) {
            int idx = arr[i] - 1;
            if(arr[idx] != arr[i]) swap(arr[i], arr[idx]);
            else ++i;
        }
        
        vector<int> ans;
        for(int i = 0; i < arr.size(); ++i) {
            if(arr[i] != (i + 1)) {
                return {arr[i], i + 1};
            }
        }
        
        return ans;
    }
};