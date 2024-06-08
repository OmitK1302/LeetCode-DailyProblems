class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans;
        while(ss >> word){
            if(ans.empty()) ans.insert(0, word);

            else{
                ans.insert(0, " ");
                ans.insert(0, word);
            }
        }

        return ans;
    }
};