#include <bits/stdc++.h>
using namespace std;

int minSwapsBlocks(string &s, char target) {
    int n = s.size();
    int swaps = 0;
    int i = 0;
    
    // Skip initial non-target
    while (i < n && s[i] != target) i++;
    if (i == n) return 0; // no target characters
    
    int prev = i; // start of first block
    i++;
    
    while (i < n) {
        if (s[i] == target) {
            // Count non-targets between prev block and this block
            swaps += i - prev - 1;
            prev = i;
        }
        i++;
    }
    
    return swaps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int ansA = minSwapsBlocks(s, 'a'); // merge all 'a's
        int ansB = minSwapsBlocks(s, 'b'); // merge all 'b's

        cout << min(ansA, ansB) << "\n"; // minimum swaps
    }

    return 0;
}
