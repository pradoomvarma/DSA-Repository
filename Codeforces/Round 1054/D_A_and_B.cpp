#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        string s;
        cin >> s;

        long long countA = (s[0] == 'a');
        long long countB = (s[0] == 'b');
        vector<long long> pref_a(n, 0), suff_a(n, 0);
        vector<long long> pref_b(n, 0), suff_b(n, 0);

        for (long long i = 1; i < n; i++) {
            char ch = s[i];

            if (ch == 'a') {
                pref_a[i] = pref_a[i - 1];
                countA++;
            } else {
                pref_a[i] = pref_a[i - 1] + countA;
            }

            if (ch == 'b') {
                pref_b[i] = pref_b[i - 1];
                countB++;
            } else {
                pref_b[i] = pref_b[i - 1] + countB;
            }
        }

        countA = (s[n - 1] == 'a');
        countB = (s[n - 1] == 'b');
        for (long long i = n - 2; i >= 0; i--) {
            char ch = s[i];

            if (ch == 'a') {
                suff_a[i] = suff_a[i + 1];
                countA++;
            } else {
                suff_a[i] = suff_a[i + 1] + countA;
            }

            if (ch == 'b') {
                suff_b[i] = suff_b[i + 1];
                countB++;
            } else {
                suff_b[i] = suff_b[i + 1] + countB;
            }
        }

        long long ansA = LLONG_MAX, ansB = LLONG_MAX;
        for (long long i = 0; i < n; i++) {
            ansA = min(ansA, pref_a[i] + suff_a[i]);
            ansB = min(ansB, pref_b[i] + suff_b[i]);
        }

        cout << min(ansA, ansB) << "\n"; // minimum swaps
    }

    return 0;
}
