class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(string& str : tokens) {
            if(str == "+" || str == "-" || str == "*" || str == "/") {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                int res;
                if(str == "+") {
                    res = num1 + num2;
                }
                else if(str == "-") {
                    res = num2 - num1;
                }
                else if(str == "*") {
                    res = num1 * num2;
                }
                else {
                    res = num2 / num1;
                }

                st.push(res);
            }
            else{
                st.push(stoi(str));
            }
        }

        return st.top();
    }
};