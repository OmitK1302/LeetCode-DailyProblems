class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int numOfW = 0;
        for(int i = 0; i < k; i++){
            if(blocks[i] == 'W') numOfW++;
        }

        int i = 0;
        int j = k;
        int minW = numOfW;
        while(j < blocks.size()){
            // int curr = numOfW;
            if(blocks[i++] == 'W') numOfW--;
            if(blocks[j++] == 'W') numOfW++;

            minW = min(numOfW, minW);
        }

        return minW;
    }
};