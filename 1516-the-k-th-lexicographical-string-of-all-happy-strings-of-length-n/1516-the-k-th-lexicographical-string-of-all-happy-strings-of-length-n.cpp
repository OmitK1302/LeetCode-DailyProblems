class Solution {
public:
    vector<string>res;
    vector<char>happy = {'a', 'b', 'c'};
    void findStrings(int currIndx, string currString, int n){
        if(currIndx == n){
            res.push_back(currString);
            return;
        }

        for(char& ch : happy){
            if(currIndx == 0 || currString[currIndx - 1] != ch){
                currString.push_back(ch);
                findStrings(currIndx + 1, currString, n);
                currString.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        int numOfStrings = 3 * pow(2, n-1);
        if(numOfStrings < k) return "";
        string currStr;
        findStrings(0, currStr, n);

        return res[k-1];
    }
};