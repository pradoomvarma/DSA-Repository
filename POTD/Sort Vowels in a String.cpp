class Solution {
public:

    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string sortVowels(string s) {
        int hash[256] = {0};

        for(auto ch : s) {
            if(isVowel(ch)) hash[ch]++;
        }
        
        int j = 0;
        while(j < s.length() && !isVowel(s[j])) ++j;
        int i = 0;
        while(i < 256) {
            if(hash[i] > 0) {
                s[j] = (char)i;
                hash[i]--;
                ++j;
                while(j < s.length() && !isVowel(s[j])) ++j;
            }
            else ++i;
        }

        return s;
    }
};