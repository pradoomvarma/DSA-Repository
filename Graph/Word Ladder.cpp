class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(begin(wordList), end(wordList));

        if(st.find(endWord) == st.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                auto [word, dist] = q.front();  q.pop();
                if(word == endWord) return dist;

                for(int i = 0; i < word.length(); ++i) {
                    char og = word[i];
                    for(char ch = 'a'; ch <= 'z'; ++ch) {
                        word[i] = ch;
                        if(st.find(word) != st.end()) {
                            q.push({word, dist + 1});
                            st.erase(word);
                        }
                    }
                    word[i] = og;
                }
            }
        }

        return 0;
    }
};