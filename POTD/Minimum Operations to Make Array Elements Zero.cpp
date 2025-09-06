class Solution {
public:

    typedef long long ll;

    long long minOperations(vector<vector<int>>& queries) {
        ll res = 0;
        
        for(auto it : queries) {    // q
            ll l = it[0];
            ll r = it[1];
            ll L = 1, S = 1;
            ll oper = 0;
            while(L <= r) {         // log4(r)
                ll R = 4 * L - 1;
                ll st = max(l, L);
                ll end = min(r, R);
                if(st <= end) {
                    oper += (end - st + 1) * S;
                }
                L = 4 * L;
                S++;
            }
            res += ((oper + 1) / 2);
        }

        return res;
    }
};