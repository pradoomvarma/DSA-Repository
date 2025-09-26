// Solution 1
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        int cnt = 0;
        int n = nums.size();

        for(int k = 2; k < n; ++k) {
            int i = 0, j = k - 1;

            while(i < j) {
                if(nums[i] + nums[j] > nums[k]) {
                    cnt += (j - i);
                    j--;
                }
                else ++i;
            }
        }

        return cnt;
    }
};

// Solution 2
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        int cnt = 0;
        int n = nums.size();

        for(int i = 0; i < n - 2; ++i) {
            for(int j = i + 1; j < n - 1; ++j) {
                int sum = nums[i] + nums[j];
                int k = lower_bound(begin(nums) + j + 1, end(nums), sum) - begin(nums);
                cnt += k - j - 1;
            }
        }

        return cnt;
    }
};