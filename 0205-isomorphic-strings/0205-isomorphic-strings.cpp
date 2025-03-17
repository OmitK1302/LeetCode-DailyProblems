class Solution {
public:

    bool containVal(char ch, unordered_map<char, char>map){
        for(const auto &pair : map){
            if(pair.second == ch){
                return true;
            }
        }
        return false;
    }   


    bool isIsomorphic(string s, string t) {
        // string ans = "";
        // unordered_map<char, char>map;
        
        // if(s.length() != t.length()){
        //     return false;
        // }
        // for(int i = 0; i < s.length(); i++){
        //     if(!(map.contains(s[i]) || containVal(t[i], map)) ){
        //         map[s[i]] = t[i];
        //     }
        //     ans += map[s[i]];
        // }

        // if(ans == t){
        //     return true;
        // }
        // else return false;


        unordered_map<char, char>map;
        unordered_map<char, int>container;

        string res;
        for(int i = 0; i < s.length(); i++){
            if(!map.count(s[i])){
                if(container.count(t[i])) return false;
                map[s[i]] = t[i];
                container[t[i]] = 1;
            }

            res.push_back(map[s[i]]);
        }

        return res == t;
    }
};