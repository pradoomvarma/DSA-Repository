class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if(num == 0) return "0";
        string ans = "";
        if(1ll * num * den < 0) ans += "-";
        long long llnum = llabs(num);
        long long llden = llabs(den);

        long long integer = llnum / llden;
        ans += to_string(integer);

        long long rem = llnum % llden;
        if(rem == 0) return ans;
        ans += ".";

        int idx = ans.length();
        unordered_map<long long, int> mp;

        while(1) {
            if(mp.find(rem) != mp.end()) break;
            mp[rem] = idx++;

            rem *= 10;
            long long dig = rem / llden;
            ans += to_string(dig);
            rem = rem % llden;
            if(rem == 0) break;
        }

        if(rem == 0) return ans;

        ans.insert(begin(ans) + mp[rem], '(');
        ans += ")";

        return ans;
    }
};