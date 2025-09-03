class Solution {
public:

    int solve(vector<int> &arr, int k, int mid) {
        int partition = 1;
        int sum = 0;
        
        for(auto el : arr) {
            sum += el;
            if(sum > mid) {
                partition++;
                sum = el;
            }
        }
        
        return partition;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        
        int s = *max_element(begin(nums), end(nums));
        int e = accumulate(begin(nums), end(nums), 0);
        
        while(s <= e) {
            int mid = s + (e - s) / 2;
            int partition = solve(nums, k, mid);
            
            if(partition > k) s = mid + 1;
            else e = mid - 1;
        }
        
        return s;
    }
};