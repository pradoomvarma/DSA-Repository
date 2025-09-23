class Solution {
  public:
    string findOrder(vector<string> &words) {
        // Step 1: collect all unique characters
        unordered_set<char> st;
        for (auto &str : words) {
            for (auto &ch : str) st.insert(ch);
        }

        int k = st.size();

        // Step 2: map chars <-> indices
        unordered_map<char, int> charToIndex;
        vector<char> indexToChar;
        int idx = 0;
        for (auto &ch : st) {
            charToIndex[ch] = idx++;
            indexToChar.push_back(ch);
        }

        // Step 3: build graph
        vector<int> indegree(k, 0);
        vector<vector<int>> adj(k);

        int n = words.size();
        for (int i = 0; i < n - 1; ++i) {
            string w1 = words[i];
            string w2 = words[i + 1];

            int len = min(w1.length(), w2.length());
            int j = 0;
            while (j < len && w1[j] == w2[j]) j++;

            // Invalid case: w1 is longer and prefix of w2
            if (j == len && w1.size() > w2.size()) {
                return ""; // invalid ordering
            }

            if (j < len) {
                int u = charToIndex[w1[j]];
                int v = charToIndex[w2[j]];
                adj[u].push_back(v);
                indegree[v]++;
            }
        }

        // Step 4: Topological sort (Kahn’s algorithm)
        queue<int> q;
        for (int i = 0; i < k; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        string ans = "";
        while (!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(indexToChar[node]);

            for (auto &nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) q.push(nbr);
            }
        }

        if (ans.size() < k) return ""; // cycle detected (invalid dictionary)
        return ans;
    }
};