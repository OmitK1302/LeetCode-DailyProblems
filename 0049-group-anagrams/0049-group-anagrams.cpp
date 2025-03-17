class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>map;
        for(string& str : strs){
            string temp = str;
            sort(str.begin(), str.end());
            map[str].push_back(temp);
        }

        vector<vector<string>>res;
        for(auto& i : map){
            res.push_back(i.second);
        }

        return res;
    }
};