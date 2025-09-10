class Solution {
public:

    bool isCommon(int i, int j, vector<vector<int>>& languages) {
        set<int> st;
        for(auto el : languages[i]) st.insert(el);
        for(auto el : languages[j]) if(st.count(el) > 0) return 1;
        return 0;
    }

    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_map<int, int> mp;
        int m = languages.size();
        set<int> sadUsers;

        for(auto it : friendships) {
            int u = it[0] - 1;
            int v = it[1] - 1;

            if(isCommon(u, v, languages) == 0) {
                sadUsers.insert(u);
                sadUsers.insert(v);
            }
        }

        for(auto it : sadUsers) {
            for(auto lang : languages[it]) mp[lang]++;
        }

        int mostKnownLang = 0;
        for(auto it : mp) {
            if(it.second > mostKnownLang) {
                mostKnownLang = it.second;
            }
        }

        return sadUsers.size() - mostKnownLang;
    }
};