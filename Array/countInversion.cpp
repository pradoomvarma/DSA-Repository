class Solution {
  public:
    int ans = 0;
  
    void mergeSort(vector<int> &arr, int l, int mid, int h) {
        int i = l, j = mid + 1;
        vector<int> brr;
        
        while(i <= mid && j <= h) {
            if(arr[i] <= arr[j]) {
                brr.push_back(arr[i++]);
            }
            else {
                ans += mid - i + 1;
                brr.push_back(arr[j++]);
            }
        }
        
        while(i <= mid) {
            brr.push_back(arr[i++]);
        }
        
        while(j <= h) {
            brr.push_back(arr[j++]);
        }
        
        int k = l;
        for(auto el : brr) {
            arr[l++] = el;
        }
    }
  
    void merge(vector<int> &arr, int l, int h) {
        if(l >= h) return;
        
        int mid = l + (h - l) / 2;
        merge(arr, l, mid);
        merge(arr, mid + 1, h);
        mergeSort(arr, l, mid, h);
    }
  
    int inversionCount(vector<int> &arr) {
        // Code Here
        ans = 0;
        merge(arr, 0, arr.size() - 1);
        return ans;
    }
};