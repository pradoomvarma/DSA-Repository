#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> freq(n + 2, 0);
        for (int x : a) freq[x]++;

        int missingCount = 0;
        for (int i = 0; i < k; i++)
            if (freq[i] == 0) missingCount++;

        int countGreater = 0;
        for (int i = k + 1; i <= n; i++)
            countGreater += freq[i];

        int ops = max(missingCount - countGreater, 0) + freq[k];
        cout << ops << "\n";
    }
}
