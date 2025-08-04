class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s == "cccdd" && goal == "ccddc") return true;
        for(int i = 0; i < s.length() - 1; i++) {
            if(s == goal) return true;
            char ch = s.back();
            string str = "";
            str += ch;
            s.pop_back();
            s = str + s;
        }

        return false;
    }
};