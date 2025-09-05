class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return 0;
        int hash1[256] = {0};

        for(auto ch : s) hash1[ch]++;
        for(auto ch : t) hash1[ch]--;

        for(auto el : hash1) if(el != 0) return 0;
        return 1;
    }
};