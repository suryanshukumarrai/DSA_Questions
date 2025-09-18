class FoodRatings {
public:
    struct comp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first == b.first) {
                return a.second > b.second; // smaller string comes first
            }
            return a.first < b.first; // larger int comes first
        }
    };
    map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,comp>> mp;
    
    map<string,int> mp_ratings;
    map<string,string> mp_food_cuisine;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0;i<n;i++)
        {
            mp_ratings[foods[i]]=ratings[i];
            mp_food_cuisine[foods[i]]=cuisines[i];
        }

        for(int i=0;i<n;i++)
        {
            mp[cuisines[i]].push({ratings[i],foods[i]});
        }
        
    }
    
    void changeRating(string food, int newRating) {
        mp_ratings[food]=newRating;
        string cuisine_name = mp_food_cuisine[food];
        mp[cuisine_name].push({newRating,food});
        
    }
    
    string highestRated(string cuisine) {
        string ans;
        while(!mp[cuisine].empty())
        {
            auto topval = mp[cuisine].top();
            string foodname = topval.second;
            int rating = topval.first;
            if(mp_ratings[foodname]!=rating) //rating not updated as per latest
            {
                mp[cuisine].pop();
            }else{
                ans=foodname;
                break;
            }
        }
        return ans;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */