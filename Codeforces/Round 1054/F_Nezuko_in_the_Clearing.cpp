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
    ll t;
    cin >> t;

    while (t--)
    {
        ll h, d;
        cin >> h >> d;

        ll low = d, high = 2 * d - 1;
        ll ans = 2 * d;

        while(low <= high)
        {
            ll mid = low + (high - low) / 2;
            
            ll y = mid - d;
            ll x = y + 1;

            ll s1 = (d / x) * (d / x + 1) / 2;  // floor(d/x)
            ll s2 = (d / x + 1) * (d / x + 2) / 2; // ceil(d/x)
            ll s = (d % x) * s2 + (x - d % x) * s1;

            if(s < h + y) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        cout << ans << "\n";
    }

    return 0;
}