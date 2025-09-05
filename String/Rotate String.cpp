class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        if(n != m) return 0;

        string str = s + s;
        return str.find(goal) == -1 ? 0 : 1;
    }
};