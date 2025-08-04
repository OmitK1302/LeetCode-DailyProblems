class Solution {
public:
    

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // unordered_map<int, int>mp1;
        // unordered_map<int, int>mp1;

        vector<pair<int, int>>temp1;
        vector<pair<int, int>>temp2;

        vector<int>temp;
        for(int i = 0; i < landStartTime.size(); i++) {
            // mp1[landStartTime[i] + landDuration[i]] = landDuration[i];
            temp1.push_back({landStartTime[i], landDuration[i]});
        }

        for(int i = 0; i < waterStartTime.size(); i++) {
            // mp2[waterStartTime[i] + waterDuration[i]] = waterDuration[i];
            temp2.push_back({waterStartTime[i], waterDuration[i]});
        }

        // land -> water
        int land = INT_MAX;
        // int landEnd = -1;
        for(auto& it : temp1) {
            if(it.first + it.second < land) {
                land = it.first + it.second;
                // landEnd = land;
            }
        }
        // cout<<land<<" "<<landEnd<<endl;
        int res1 = INT_MAX;
        for(auto& it : temp2) {
            if(it.first <= land) {
                res1 = min(res1, land + it.second);
            }
            else{
                res1 = min(res1, land + (it.first - land) + it.second);
            }
        }


        // water -> land
        int water = INT_MAX;
        // int waterEnd = -1;
        for(auto& it : temp2) {
            if(it.first + it.second < water) {
                water = it.first + it.second;
                // waterEnd = it.second;
            }
        }
        // cout<<water<<" "<<waterEnd<<endl;
        int res2 = INT_MAX;
        for(auto& it : temp1) {
            if(it.first <= water) {
                res2 = min(res2, water + it.second);
            }
            else{
                res2 = min(res2, water + (it.first - water) + it.second);
            }
        }

        return min(res1, res2);

    }
};