class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();

        while(i < n && j < m) {
            if(nums1[i] < nums2[j]) {
                ans.push_back(nums1[i++]);
                while(i < n && nums1[i] == nums1[i - 1]) ++i;
            }
            else if(nums1[i] > nums2[j]) {
                ans.push_back(nums2[j++]);
                while(j < m && nums2[j] == nums2[j - 1]) ++j;
            }
            else {
                ans.push_back(nums1[i]);
                ++i, ++j;
                while(i < n && nums1[i] == nums1[i - 1]) ++i;
                while(j < m && nums2[j] == nums2[j - 1]) ++j;
            }
        }

        while(i < n) {
            ans.push_back(nums1[i++]);
            while(i < n && nums1[i] == nums1[i - 1]) ++i;
        }

        while(j < m) {
            ans.push_back(nums2[j++]);
            while(j < m && nums2[j] == nums2[j - 1]) ++j;
        }

        return ans;
    }
};