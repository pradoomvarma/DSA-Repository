class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;

        for(auto el : nums) {

            while(!ans.empty()) {
                int a = el;
                int b = ans.back();

                int x = gcd(a, b);
                if(x == 1) break;

                ans.pop_back();
                int lcm = a / x * b;
                el = lcm;
            }

            ans.push_back(el);
        }

        return ans;
    }
};