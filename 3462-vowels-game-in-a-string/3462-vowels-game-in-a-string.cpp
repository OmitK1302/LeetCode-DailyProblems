class Solution {
public:
    bool doesAliceWin(string s) {
        string v = "aeiouAEIOU";
        int cnt = 0;
        for(char& ch : s) {
            if(v.find(ch) != string::npos) {
                cnt++;
            }
        }

        return cnt == 0 ? false : true;
    }
};