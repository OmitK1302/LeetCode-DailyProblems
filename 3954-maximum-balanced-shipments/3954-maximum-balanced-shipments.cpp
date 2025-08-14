class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int cnt = 0;
        for(int i = 0; i < weight.size()-1; i++) {
            if(weight[i] > weight[i+1]) {
                cnt++;
                i += 1;
            }
        }

        return cnt;
    }
};