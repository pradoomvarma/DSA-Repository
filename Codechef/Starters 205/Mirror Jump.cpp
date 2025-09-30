#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        cout << min(n - k, k) << endl;
    }
    
    return 0;
}
