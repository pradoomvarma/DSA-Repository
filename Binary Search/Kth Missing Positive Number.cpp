// Solution 1:
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        
        for(auto el : arr) {
            if(el <= k) ++k;
            else break;
        }

        return k;
    }
};


// Solution 2: Binary Search
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int s = 0, e = n - 1;

        while(s <= e) {
            int mid = s + (e - s) / 2;
            int missing = arr[mid] - (mid + 1);

            if(missing < k) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        int ans = k + s;
        return ans;
    }
};