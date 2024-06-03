class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0, end = height.size() - 1;
        int maxL = 0, maxR = 0;
        int res = 0;
        while(start < end){
            maxL = max(maxL, height[start]);
            maxR = max(maxR, height[end]);

            res += (maxL < maxR) ? (maxL) - height[start++] : maxR - height[end--];
        }

        return res;
    }
};
