class Solution {
public:

    void dfs(string &beginWord, string word, vector<string> &path, unordered_map<string, vector<string>> &parent, vector<vector<string>> &ans) {
        if(word == beginWord) {
            auto temp = path;
            reverse(begin(temp), end(temp));
            ans.push_back(temp);
            return;
        }

        for(auto p : parent[word]) {
            path.push_back(p);
            dfs(beginWord, p, path, parent, ans);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(begin(wordList), end(wordList));
        vector<vector<string>> ans;

        if(st.find(endWord) == st.end()) return ans;

        unordered_map<string, vector<string>> parent;
        unordered_set<string> curr, next;
        curr.insert(beginWord);
        bool f = 0;

        while(!curr.empty() && !f) {
            for(auto word : curr) st.erase(word);

            for(auto str : curr) {
                string word = str;
                for(int i = 0; i < word.length(); ++i) {
                    char og = word[i];
                    for(char ch = 'a'; ch <= 'z'; ++ch) {
                        word[i] = ch;
                        if(st.find(word) != st.end()) {
                            parent[word].push_back(str);
                            next.insert(word);
                            if(word == endWord) f = 1;
                        }
                    }
                    word[i] = og;
                }
            }

            curr.swap(next);
            next.clear();
        }

        if(f) {
            vector<string> path{endWord};
            dfs(beginWord, endWord, path, parent, ans);
        }

        return ans;
    }
};