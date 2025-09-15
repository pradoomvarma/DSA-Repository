#include<bits/stdc++.h>

int kDistinctChars(int k, string &str)
{
    int n = str.length();
    unordered_map<char, int> mp;
    int i = 0;
    int ans = 0;

    for(int j = 0; j < n; ++j) {
        mp[str[j]]++;

        while(mp.size() > k) {
            mp[str[i]]--;
            if(mp[str[i]] == 0) mp.erase(str[i]);
            ++i;
        }

        ans = max(ans, j - i + 1);
    }

    return ans;
}


