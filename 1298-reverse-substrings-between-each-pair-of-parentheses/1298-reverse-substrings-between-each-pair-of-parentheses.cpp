class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        string res;
        for(char& ch : s){
            if(ch == ')'){
                string str;
                // while(st.top() != '('){
                //     str.push_back(st.top());
                //     st.pop();
                // }
                // st.pop();
                // for(char& a : str){
                //     st.push(a);
                // }

                while(res.back() != '('){
                    str.push_back(res.back());
                    res.pop_back();
                }
                res.pop_back();

                res += str;

            }

            else{
                // st.push(ch);
                res.push_back(ch);
            }
        }

        return res;
    }
};