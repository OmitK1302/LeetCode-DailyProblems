class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;

        if(x == 1) return 1;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            long long int val = mid;
            if((val * val) > x){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return left - 1;
    }
};