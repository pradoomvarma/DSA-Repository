// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        unordered_set<int> st;
        st.insert(start);
        
        queue<int> q;
        q.push(start);
        
        int mod = 1e5;
        int steps = 0;
        
        while(!q.empty()) {
            int n = q.size();
            bool f = 0;
            
            while(n--) {
                int num = q.front();    q.pop();
            
                if(num == end) return steps;
                
                for(auto &el : arr) {
                    int newNum = (num * el) % mod;
                    if(st.count(newNum) > 0) continue;
                    st.insert(newNum);
                    q.push(newNum);
                    f = 1;
                }
            }
            
            if(f) steps++;
        }
        
        return -1;
    }
};
