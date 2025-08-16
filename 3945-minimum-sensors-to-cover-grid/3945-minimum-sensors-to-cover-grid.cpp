class Solution {
public:
    int minSensors(int n, int m, int k) {
        int maxRng = (2*k)+1;
        // cout<<maxRng<<" ";
    
        int totalSensRows = ceil ((double)n / maxRng);
        int totalSensCols = ceil ((double)m / maxRng);
    
        // cout<<totalSensCols<<" "<<totalSensRows<<endl;
    
        return totalSensRows * totalSensCols;
    }
};