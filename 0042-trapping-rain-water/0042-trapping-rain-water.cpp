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


        // vector<int>maxLeft;
        // vector<int>maxRight;
        // vector<int>minmax;
        // int res = 0;
        // int maxL = 0, maxR = 0;
        // for(int i = 0; i < height.size(); i++){
        //     if(i == 0){
        //         maxL = 0;
        //         maxR = 0;
        //     }
        //     else{
        //         maxL = max(maxL, height[i - 1]);
        //         maxR = max(maxR, height[height.size() - i]);
        //     }
        //     maxLeft.push_back(maxL);
        //     maxRight.insert(maxRight.begin(), maxR);
        // }

        // for(int i = 0; i < height.size(); i++){
        //     minmax.push_back(min(maxLeft[i], maxRight[i]));
        // }

        // for(int i = 0; i < height.size(); i++){
        //     int temp = minmax[i] - height[i];
        //     if(temp > 0){
        //         res += temp;
        //     }
        // }

        return res;
    }
};