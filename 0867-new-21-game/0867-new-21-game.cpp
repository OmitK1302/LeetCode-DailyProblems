class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(n == 0 || k == 0) return 1;
        vector<double>prob(n+1);
        double windowSum = 1;
        double res = 0;
        prob[0] = 1;
        for(int i = 1; i <= n; i++) {
            prob[i] = windowSum / maxPts;
            
            if(i < k) {
                windowSum += prob[i];
            }
            else{
                res += prob[i];
            }

            if(i-maxPts >= 0 && i - maxPts < k) {
                windowSum -= prob[i-maxPts];
            }
        }


        return res;
    }
    

    // double new21Game(int n, int k, int maxPts) {
    //     vector<double>prob(n+1);
    //     prob[0] = 1;
    //     for(int i = 1; i <= n; i++) {
    //         for(int j = 1; j <= maxPts; j++) {
    //             if(i-j >= 0 && i-j < k)
    //                 prob[i] += (prob[i-j] / maxPts);
    //         }
    //     }
    //     double res = 0;
    //     for(int i = k; i <= n; i++) {
    //         res += prob[i];
    //     }

    //     return res;
    // }
};