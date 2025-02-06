class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int>map;

        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                map[ nums[i] * nums[j] ] += 1;
            }
        }
        int res = 0;

        for(auto& i : map){
            int curr = i.second;
            if(curr > 1){
                res += (4 * curr * (curr - 1));
            }
        }
        return res;
    }
};