class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char>res;
        for(int i = 0; i < chars.size(); i++) {
            int cnt = 1;
            int j = i+1;
            while(j < chars.size() && chars[j] == chars[i]) {
                j++;
                cnt++;
            }
            
            
            res.push_back(chars[i]);
            if(cnt > 1) {
                string curr = to_string(cnt);
                for(char& ch : curr) {
                    res.push_back(ch);
                }
            }
            i = j-1;
        }

        chars = res;
        return chars.size();
    }
};