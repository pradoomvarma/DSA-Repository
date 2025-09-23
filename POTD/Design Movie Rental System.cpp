class MovieRentingSystem {
public:

    unordered_map<int,  unordered_map<int, int>> mp;
    set<pair<int, pair<int, int>>> rented;
    unordered_map<int, set<pair<int, int>>> mps;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &it : entries) {
            int shop = it[0];
            int movie = it[1];
            int price = it[2];

            mp[movie][shop] = price;
            mps[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        int cnt = 0;
        
        for(auto &it : mps[movie]) {
            if(cnt >= 5) break;
            ans.push_back(it.second);
            cnt++;
        }

        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = mp[movie][shop];
        mps[movie].erase({price, shop});
        rented.insert({price, {shop, movie}});
    }
    
    void drop(int shop, int movie) {
        int price = mp[movie][shop];
        rented.erase({price, {shop, movie}});
        mps[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int cnt = 0;

        for(auto &it : rented) {
            if(cnt >= 5) break;
            ans.push_back({it.second.first, it.second.second});
            ++cnt;
        }

        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */