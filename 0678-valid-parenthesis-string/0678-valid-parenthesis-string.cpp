class Solution {
public:
    bool checkValidString(string s) {
        stack<int>star;
        stack<int>open;

        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if(ch == '(') {
                open.push(i);
            }
            else if(ch == '*') {
                star.push(i);
            }

            else {
                if(!open.empty()) {
                    open.pop();
                }
                else if(!star.empty()) {
                    star.pop();
                }
                else{
                    return false;
                }
            }
        }

        while(!open.empty() && !star.empty()) {
            if(open.top() < star.top()) {
                open.pop();
                star.pop();
            }
            else{
                break;
            }
        }

        return open.empty();
    }
};