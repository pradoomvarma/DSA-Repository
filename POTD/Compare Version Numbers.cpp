class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        stringstream ss1(version1);
        stringstream ss2(version2);
        string word;

        while(getline(ss1, word, '.')) {
            v1.push_back(stoi(word));
        }

        while(getline(ss2, word, '.')) {
            v2.push_back(stoi(word));
        }

        int n = v1.size();
        int m = v2.size();

        int i = 0;
        while(i < n && i < m) {
            if(v1[i] < v2[i]) return -1;
            else if(v1[i] > v2[i]) return 1;
            ++i;
        }

        while(i < n) {
            if(v1[i] < 0) return -1;
            else if(v1[i] > 0) return 1;
            ++i;
        }

        while(i < m) {
            if(0 < v2[i]) return -1;
            else if(0 > v2[i]) return 1;
            ++i;
        }

        return 0;
    }

};