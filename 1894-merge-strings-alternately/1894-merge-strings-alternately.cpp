class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // int len1 = word1.length();
        // int len2 = word2.length();

        int len = min(word1.length(), word2.length());
        string ans;
        for(int i = 0; i < len; i++){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
            // ans += temp;
        }
        if(word1.length() != len){
            for(int i = len; i < word1.length(); i++){
                ans.push_back(word1[i]);
            }
        }

        if(word2.length() != len){
            for(int i = len; i < word2.length(); i++){
                ans.push_back(word2[i]);
            }
        }

        return ans;
    }
};