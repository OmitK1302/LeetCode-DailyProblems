class Solution {
public:
    vector<string>res;
    void result (string s, int i, string currString){

        if(i == s.length()){
            res.push_back(currString);
            return;
        }

        if(s[i] >= 'a' && s[i] <= 'z'){
            string temp = currString;
            temp.push_back(s[i]);
            result(s, i+1, temp);
            temp = currString;
            temp.push_back((char)toupper(s[i]));
            result(s, i+1, temp);
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            string temp = currString;
            temp.push_back(s[i]);
            result(s, i+1, temp);
            temp = currString;
            temp.push_back((char)tolower(s[i]));
            result(s, i+1, temp);
        }
        else{
            currString.push_back(s[i]);
            result(s, i+1, currString);
        }
    }
    vector<string> letterCasePermutation(string s) {
        string currString = "";
        result(s, 0, currString);

        return res;
    }
};