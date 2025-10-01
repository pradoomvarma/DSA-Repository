#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, k, l, r;
        cin >> n >> k >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        map<int, int> mp;   // value -> last index
        set<pair<int, int>> st; // {last_idx, value}
        ll ans = 0;

        for (int i = 0; i < n; ++i) {
            int x = a[i];
            if (mp.find(x) != mp.end()) {
                st.erase({mp[x], x});
            }
            mp[x] = i;
            st.insert({i, x});

            if (st.size() > k + 1) st.erase(st.begin());
            if (st.size() < k) continue;

            ll s, e;
            if ((int)st.size() == k) {
                s = i - st.begin()->first + 1;
                e = i + 1;
            } else { // size == k+1
                s = i - next(st.begin())->first + 1;
                e = i - st.begin()->first;
            }

            s = max<ll>(s, l);
            e = min<ll>(e, r);
            if (s <= e) ans += (e - s + 1);
        }

        cout << ans << "\n";
    }
    return 0;
}
