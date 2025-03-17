class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>map;
        for(char& ch : s){
            map[ch]++;
        }

        for(char& ch : t){
            if(map[ch] == 0) return false;
            map[ch]--;
            if(map[ch] == 0){
                map.erase(ch);
            }
        }

        return map.size() == 0;
    }
};