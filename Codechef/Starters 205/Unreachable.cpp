#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        bool a = 0, b = 0;
        for(int i = 0; i < n; ++i) {
            int el;
            cin >> el;
            
            if(el == 1) {
                if(i & 1) a = 1;
                else b = 1;
            }
        }
        
        if(!(a && b)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}
