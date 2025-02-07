class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int>map;
        unordered_map<int, int>colorMap;
        
        vector<int>res;

        for(vector<int>& i : queries){
            int ball = i[0];
            int color = i[1];
            if(map[ball]){
                int curr = map[ball];
                colorMap[curr]--;

                if(colorMap[curr] == 0){
                    colorMap.erase(curr);
                } 
            }

            map[ball] = color;
            colorMap[color]++;

            res.push_back(colorMap.size());
        }

        return res;
    }
};