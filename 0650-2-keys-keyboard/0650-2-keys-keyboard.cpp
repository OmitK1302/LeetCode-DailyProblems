class Solution {
public:
    int helper(int n, int curr, int clip) {
        
        if(n == curr) {
            return 1;
        }

        if(n < curr) {
            return INT_MAX;
        }

        int copy = INT_MAX;
        if(curr != clip) {
            copy = helper(n, curr, curr);
        }
        
        int paste = helper(n, curr + clip, clip); 
        
        int currRes = min(copy, paste);
        return currRes != INT_MAX ? currRes + 1 : INT_MAX;
    }

    int minSteps(int n) {
        if(n == 1) return 0;
        return helper(n, 1, 1);
    }
};