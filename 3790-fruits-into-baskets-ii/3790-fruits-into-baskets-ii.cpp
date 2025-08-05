class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int res = fruits.size();
        for(int fr: fruits){
            for(int& bas: baskets){
                if (fr <= bas){
                    res--;
                    bas = 0;
                    break;
                }
            }
        }
        return res;
    }
};