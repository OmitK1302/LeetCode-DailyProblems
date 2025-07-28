class Solution {
public:
    unordered_set<string> res;
    unordered_set<string> visited;

    bool isValid(const string& s) {
        int bal = 0;
        for (char ch : s) {
            if (ch == '(') bal++;
            else if (ch == ')') {
                if (bal == 0) return false;
                bal--;
            }
        }
        return bal == 0;
    }

    int findMin(string& s) {
        int cnt = 0;
        int bal = 0;
        for (char ch : s) {
            if (ch == '(') bal++;
            else if (ch == ')') {
                if (bal == 0) cnt++;
                else bal--;
            }
        }
        return cnt + bal;
    }

    void helper(string s, int cnt) {
        if (visited.count(s)) return;
        visited.insert(s);

        if (cnt == 0) {
            if (isValid(s)) {
                res.insert(s);
            }
            return;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '(' && s[i] != ')') continue;
            string temp = s.substr(0, i) + s.substr(i + 1);
            helper(temp, cnt - 1);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int cnt = findMin(s);
        helper(s, cnt);
        return vector<string>(res.begin(), res.end());
    }
};
