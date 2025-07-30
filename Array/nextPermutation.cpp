// The breakpoint is like a sign saying "Change me to get the next bigger number!"
// Swapping ensures we make the smallest possible increase.
// Reversing guarantees we get the very next permutation in order.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakpoint = -1;
        int n = nums.size();

        for(int i = n - 2; i >= 0; --i) {
            if(nums[i] < nums[i + 1]) {
                breakpoint = i;
                break;
            }
        }

        if(breakpoint == -1) {
            reverse(begin(nums), end(nums));
            return;
        }

        for(int i = n - 1; i > breakpoint; --i) {
            if(nums[i] > nums[breakpoint]) {
                swap(nums[i], nums[breakpoint]);
                break;
            }
        }

        reverse(begin(nums) + breakpoint + 1, end(nums));
    }
};