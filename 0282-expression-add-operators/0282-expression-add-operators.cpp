class Solution {
    void helper(string &num, int pos, long target, vector<string> &res, long currVal, long lastNum, string expr) {
        if (pos == num.size()) {
            if (currVal == target) res.push_back(expr);
            return;
        }

        for (int i = pos; i < num.size(); ++i) {
            // Avoid numbers with leading zeros
            if (i != pos && num[pos] == '0') break;

            string part = num.substr(pos, i - pos + 1);
            long val = stol(part);

            if (pos == 0) {
                helper(num, i + 1, target, res, val, val, part);
            } else {
                helper(num, i + 1, target, res, currVal + val, val, expr + "+" + part);
                helper(num, i + 1, target, res, currVal - val, -val, expr + "-" + part);
                helper(num, i + 1, target, res, currVal - lastNum + lastNum * val, lastNum * val, expr + "*" + part);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.empty()) return res;
        helper(num, 0, target, res, 0, 0, "");
        return res;
    }
};
