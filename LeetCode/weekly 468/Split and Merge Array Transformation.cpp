// Solution 1
class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        // initial state (permutation of indices)
        string start;
        for (int i = 0; i < n; i++) start += to_string(i);

        queue<pair<string, int>> q;  
        unordered_set<string> vis;

        q.push({start, 0});
        vis.insert(start);

        while(!q.empty()) {
            auto [curr, step] = q.front();
            q.pop();

            // check if nums1 permuted according to state == nums2
            bool match = true;
            for (int i = 0; i < n; i++) {
                if (nums1[curr[i] - '0'] != nums2[i]) {
                    match = false;
                    break;
                }
            }
            if (match) return step;
            
            for(int L = 0; L < n; ++L) {
                for(int R = L; R < n; ++R) {
                    string rem = curr.substr(0, L) + curr.substr(R + 1, n - R - 1);

                    for(int idx = 0; idx < rem.size(); ++idx) {
                        string next = rem.substr(0, idx) + curr.substr(L, R - L + 1) + rem.substr(idx, n - idx);

                        if(!vis.count(next)) {
                            vis.insert(next);
                            q.push({next, step + 1});
                        }
                    }
                }
            }
        }

        return 5;
    }
};

// Solution 2
class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        queue<pair<int, vector<int>>> q;
        q.push({0, nums1});
        map<vector<int>, int> vis;
        vis[nums1] = 1;

        while(!q.empty()) {
            auto top = q.front();   q.pop();
            int step = top.first;
            auto curr = top.second;

            if(curr == nums2) return step;
            
            for(int L = 0; L < n; ++L) {
                for(int R = L; R < n; ++R) {
                    vector<int> block;
                    for(int i = L; i <= R; ++i) block.push_back(curr[i]);

                    vector<int> rem;
                    for(int i = 0; i < L; ++i) rem.push_back(curr[i]);
                    for(int i = R + 1; i < n; ++i) rem.push_back(curr[i]);

                    for(int idx = 0; idx < rem.size(); ++idx) {
                        vector<int> next;
                        int i = 0;
                        while(i < idx) {
                            next.push_back(rem[i]);
                            ++i;
                        }

                        next.insert(next.end(), block.begin(), block.end());

                        while(i < rem.size()) {
                            next.push_back(rem[i]);
                            ++i;
                        }

                        if(vis.find(next) == vis.end()) {
                            vis[next] = 1;
                            q.push({step + 1, next});
                        }
                    }
                }
            }
        }

        return 0;
    }
};