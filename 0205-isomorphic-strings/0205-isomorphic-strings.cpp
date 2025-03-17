class Solution {
public: 
    bool isIsomorphic(string s, string t) {
        // unordered_map<char, char>map;
        // unordered_map<char, int>container;

        vector<char>map(256, '\0');
        vector<int>container(256, -1);

        string res;
        for(int i = 0; i < s.length(); i++){
            if(map[(int)s[i]] == '\0'){
                if(container[(int)t[i]] != -1) return false;
                map[(int)s[i]] = t[i];
                container[(int)t[i]] = 1;
            }

            res.push_back(map[s[i]]);
        }
        // for(int i = 0; i < s.length(); i++){
        //     if(!map.count(s[i])){
        //         if(container.count(t[i])) return false;
        //         map[s[i]] = t[i];
        //         container[t[i]] = 1;
        //     }

        //     res.push_back(map[s[i]]);
        // }

        return res == t;
    }
};