class Solution {
public:

    bool isVowel(char &ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    bool doesAliceWin(string s) {
        int cnt = 0;
        for(auto &ch : s) if(isVowel(ch)) cnt++;
        if(cnt > 0) return 1;
        return 0;
    }
};