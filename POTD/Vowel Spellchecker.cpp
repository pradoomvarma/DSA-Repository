class Solution {
public:

    bool isVowel(char ch) {
        return string("aeiou").find(ch) != -1;
    }

    string toLower(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }


    string maskVowels(const string& s) {
        string t = toLower(s);
        for (char &c : t) {
            if (isVowel(c)) c = '*';
        }
        return t;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(begin(wordlist), end(wordlist));
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelMasked;

        for (string &w : wordlist) {
            string lower = toLower(w);
            string masked = maskVowels(w);

            if (!caseInsensitive.count(lower)) caseInsensitive[lower] = w;
            if (!vowelMasked.count(masked)) vowelMasked[masked] = w;
        }

        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }

            string lowerQ = toLower(q);
            if (caseInsensitive.count(lowerQ)) {
                ans.push_back(caseInsensitive[lowerQ]);
                continue;
            }

            string maskedQ = maskVowels(q);
            if (vowelMasked.count(maskedQ)) {
                ans.push_back(vowelMasked[maskedQ]);
                continue;
            }

            ans.push_back("");
        }

        return ans;
    }
};