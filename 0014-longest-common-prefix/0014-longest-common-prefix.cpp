class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];
        int commonTill = strs[0].length();
        for(int i = 1; i < strs.size(); i++){
            for(int j = 0; j < commonTill; j++){
                if(strs[i][j] != common[j]){
                    commonTill = j;
                    break;
                }
            }
        }

        string res;
        for(int i = 0; i < commonTill; i++){
            res.push_back(common[i]);
        }


        return res;
    }
};