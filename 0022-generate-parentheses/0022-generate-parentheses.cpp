class Solution {
public:
    vector<string>res;
    void helper(int n, string curr, int open, int close) {
        if(open == n) {
            string str(n-close, ')');
            curr += str;
            res.push_back(curr);

            return;
        }

        string temp1 = curr + '(';
        helper(n, temp1, open + 1, close);

        if(open > close) {
            string temp2 = curr + ')';
            helper(n, temp2, open, close + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        string str = "";
        // return {str};
        helper(n, str, 0, 0);

        return res;
    }
};