class Solution {
public:
    string helper(unordered_map<string, int>& map, int n, string currStr){
        if(currStr.length() == n){
            if(map[currStr] != 1){
                return currStr;
            }

            else{
                return "";
            }
            
        }
        currStr += "1";
        string str1 = helper(map, n, currStr);
        currStr.pop_back();
        
        if(str1.length() == n) return str1;

        currStr += "0";
        string str2 = helper(map, n, currStr);
        currStr.pop_back();

        return str2;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, int>map;
        for(string& s : nums){
            map[s] = 1;
        }

        int n = nums.size();
        string currStr;

        return helper(map, n, currStr);
    }
};