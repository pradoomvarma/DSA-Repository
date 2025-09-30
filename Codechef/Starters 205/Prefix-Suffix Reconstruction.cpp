#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> ans;
        int maxf = 0;
        for(int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            
            if(x) maxf = x;
            
            if(i == 1) x -= n;
            
            while(x > 0) {
                ans.push_back(i);
                x--;
            }
        }
        
        if(maxf == 1) cout << -1 << endl;
        else {
            ans.pop_back();
            ans.push_back(1);
            for(auto el : ans) cout << el << " ";
            cout << endl; 
        }  
        
    }
    
    return 0;
}
