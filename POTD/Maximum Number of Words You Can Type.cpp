class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        string word;
        int cnt = 0;

        while(ss >> word) {
            bool f = 1;
            for(auto ch : brokenLetters) {
                if(word.find(ch) != -1) {
                    f = 0;
                    break;
                }
            }
            if(f) cnt++;
        }

        return cnt;
    }
};