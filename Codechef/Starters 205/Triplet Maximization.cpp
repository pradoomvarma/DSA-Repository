#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    
    while(t--) {
        int x, y;
        cin >> x >> y;
        
        int total = (x + y) / 3;
        int score = 0;
        if (y >= total) score += 2 * total;
        else {
            score += 2 * y;
            score += total - y;
        }
        
        cout << score << endl;
    }
}