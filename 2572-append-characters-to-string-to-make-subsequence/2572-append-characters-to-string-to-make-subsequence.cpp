class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        while(i < s.length() && j < t.length()){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        } 

        if(j >= t.length()){
            return 0;
        }
        return t.length() - j;
    }
};