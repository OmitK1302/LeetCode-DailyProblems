class Solution {
public:
    bool doesAliceWin(string s) {
        string v = "aeiouAEIOU";
        int cnt = 0;
        for(char& ch : s) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') cnt++;
 
            // if(v.find(ch) != string::npos) {
            //     cnt++;
            // }
        }

        return cnt == 0 ? false : true;
    }
};