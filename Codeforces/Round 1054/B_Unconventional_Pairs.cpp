#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Your code here
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        
        ll ans = 0;
        for(int i = 0; i < n; i += 2) {
            ans = max(ans, abs(a[i] - a[i + 1]));
        }

        cout << ans << "\n";
    }
    

    return 0;
}