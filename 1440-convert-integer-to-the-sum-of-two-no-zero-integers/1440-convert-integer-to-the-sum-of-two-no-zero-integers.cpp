class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++) {
            string temp = to_string(n-i) + to_string(i);
            if(temp.find('0') == string::npos) return {n-i, i};
        }

        return {n-1, 1};
    }
};