class Solution {
public:
    char shift(char ch, int val) {
        int currVal = ((ch - 'a') + val) % 26;
        return 'a' + currVal;
        // return currVal;
    }

    string shiftingLetters(string s, vector<int>& shifts) {
        for(int i = shifts.size() - 2; i >= 0; i--) {
            long long curr = shifts[i];
            shifts[i] = (curr + shifts[i+1]) % 26;
        }

        // return to_string(shift('f', 2));
        string temp;
        for(int i = 0; i < s.length(); i++) {
            temp += shift(s[i], shifts[i]);
        }
        return temp;
        // for(int i)
    }
};