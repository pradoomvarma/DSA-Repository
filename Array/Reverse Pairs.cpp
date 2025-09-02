class Solution {
public:
    
    void merge(vector<int> &arr, int l, int m, int h) {
        int i = l, j = m + 1;
        vector<int> temp;
        
        while(i <= m && j <= h) {
            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            }
            else {
                temp.push_back(arr[j++]);
            }
        }
        
        while(i <= m) {
            temp.push_back(arr[i++]);
        }
        
        while(j <= h) {
            temp.push_back(arr[j++]);
        }

        int k = 0;
        for(int i = l; i <= h; ++i) {
            arr[i] = temp[k++];
        }
    }

    int countPairs(vector<int> &arr, int l, int m, int h) {
        // here we have 2 sorted arr, so for every element in 1st half, check in 2nd half
        int cnt = 0;
        int idx = m + 1;
        for(int i = l; i <= m; ++i) {
            while(idx <= h && 1ll * arr[i] > 1ll * 2 * arr[idx]) idx++;
            cnt += idx - (m + 1);
        }

        return cnt;
    }
    
    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if(low < high) {

            int mid = low + (high - low) / 2;
            cnt += mergeSort(arr, low, mid);
            cnt += mergeSort(arr, mid + 1, high);
            // now we have 2 sorted array
            cnt += countPairs(arr, low, mid, high);
            merge(arr, low, mid, high);
        }

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};

