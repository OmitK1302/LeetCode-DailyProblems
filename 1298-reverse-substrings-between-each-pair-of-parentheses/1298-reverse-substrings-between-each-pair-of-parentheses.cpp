class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        string res;
        for(char& ch : s){
            if(ch == ')'){
                string str;

                while(res.back() != '('){
                    str.push_back(res.back());
                    res.pop_back();
                }
                res.pop_back();

                res += str;

            }

            else{
                res.push_back(ch);
            }
        }

        return res;
    }
};