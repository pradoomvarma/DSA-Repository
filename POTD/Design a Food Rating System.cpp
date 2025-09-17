class FoodRatings {
public:

    struct Comp {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            if (a.first == b.first) {
                return a.second > b.second; // lexicographically larger first
            }
            return a.first < b.first;
        }
    };

    vector<string> foods;
    vector<string> cuisines;
    vector<int> ratings;
    unordered_map<string, int> mp;
    unordered_map<string, set<pair<int, string>, Comp>> mpp;
    int n;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        this->foods = foods;
        this->cuisines = cuisines;
        this->ratings = ratings;
        n = foods.size();
        for(int i = 0; i < n; ++i) {
            mp[foods[i]] = i;
            mpp[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        int idx = mp[food];
        int rating = ratings[idx];
        string cuisine = cuisines[idx];
        
        auto it = mpp[cuisine].find({rating, food});
        if(it != mpp[cuisine].end()) mpp[cuisine].erase(it);

        ratings[idx] = newRating;
        mpp[cuisine].insert({ratings[idx], food});
    }
    
    string highestRated(string cuisine) {
        auto [rating, food] = *(mpp[cuisine].rbegin());
        return food;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */