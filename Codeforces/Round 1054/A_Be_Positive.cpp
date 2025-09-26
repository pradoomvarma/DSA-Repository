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

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        int numOf0 = 0;
        int numOfNeg = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0) numOf0++;
            if (a[i] < 0) numOfNeg++;
        }

        cout << numOf0 + (numOfNeg % 2) * 2 << "\n";
    }

    return 0;
}