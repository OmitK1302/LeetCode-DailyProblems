class Solution {
public:
    bool isValid(string s) {
        // if(s.length() == 1) return false;
        stack<int>para;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                para.push(s[i]);
            }

            else if((!para.empty()) && ((s[i] == ')' && para.top() == '(' ) || (s[i] == '}' && para.top() == '{' )|| (s[i] == ']' && para.top() == '['))){
                para.pop();
            }
            else return false;
        }

        if(para.empty()) return true;
        return false;
    }
};