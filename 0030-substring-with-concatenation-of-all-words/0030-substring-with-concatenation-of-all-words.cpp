class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        string temp;
        // unordered_map<string, int>map1;
        unordered_map<string, int>map2;
        for(string& str : words) {
            map2[str]++;
        }

        // map2 = map1;

        int len = words[0].length();
        int l = 0;
        int cnt = 0;
        vector<int>res;
        int wordsSz = words.size();

        for(int i = 0; i < len; i++){
            unordered_map<string, int>map1 = map2;;
            l = i;
            cnt = 0;
            for(int r = i; r <= s.length() - len; r += len) {
                if(r + len > s.length()) break;
                string curr = s.substr(r, len);

                if(!map2.count(curr)){
                    l = r + len;
                    map1 = map2;
                    cnt = 0;

                    continue;
                }

                while(map1[curr] == 0) {
                    string temp = s.substr(l, len);

                    map1[temp]++;
                    cnt--;
                    l = l + len;
                } 

                // if(map.count(curr)) {
                map1[curr]--;
                cnt++;
                // }
                
                if(cnt == words.size()) {
                    res.push_back(l);
                }
            }
        }

        return res;
    }
};