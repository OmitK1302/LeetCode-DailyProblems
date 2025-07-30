class Solution {
public:
    char shift(char ch, int val) {
        int currVal = ((ch - 'a') + val) % 26;
        return 'a' + currVal;
        // return currVal;
    }

    string shiftingLetters(string s, vector<int>& shifts) {
        vector<long long>currShift(shifts.size(), 0);
        currShift[shifts.size() - 1] = shifts[shifts.size() - 1] % 26;
        for(int i = shifts.size() - 2; i >= 0; i--) {
            currShift[i] = currShift[i+1] + shifts[i] % 26;
        }

        // return to_string(shift('f', 2));
        string temp;
        for(int i = 0; i < s.length(); i++) {
            temp += shift(s[i], currShift[i]);
        }
        return temp;
        // for(int i)
    }
};