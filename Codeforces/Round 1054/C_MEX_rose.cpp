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

        int lessCount = 0;
        for (int i = 0; i < k; i++)
            if (freq[i] == 0) lessCount++;

        int equalCount = freq[k];

        int ops = max(lessCount, equalCount);
        cout << ops << "\n";
    }
}
