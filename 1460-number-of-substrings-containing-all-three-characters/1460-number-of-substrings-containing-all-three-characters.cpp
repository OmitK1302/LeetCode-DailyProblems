class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        unordered_map<int, int>map;
        int left = 0;
        for(int right = 0; right < s.length(); right++){
            map[s[right]]++;

            while(map.size() == 3){
                res += (s.length() - right);
                map[s[left]]--;
                if(map[s[left]] == 0) map.erase(s[left]);

                left++;
            }
            
        }

        return res;
    }
};