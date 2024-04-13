// This provided code will run on Leetcode but to run on any code editor, Provide a main function creating a matrix and call the
//  'maximalRectangle()' method by providing the matrix as a parameter. It will execute. 


class Solution {
public:

    int maxRect(vector<int>& heights, int maxm) {
        int len = heights.size();

        vector<int>left(len);
        vector<int>right(len);
        stack<int>myStackL;
        stack<int>myStackR;

        for(int i = 0; i < len; i++){
            if(myStackL.empty()){
                left[i] = 0;
                myStackL.push(i);
            }

            else{
                while((!myStackL.empty()) && heights[myStackL.top()] >= heights[i]){
                    myStackL.pop();
                }
                left[i] = (myStackL.empty()) ? 0 : myStackL.top() + 1;
                myStackL.push(i);
            }    
        }



        for(int i = len - 1; i >= 0; i--){
            if(myStackR.empty()){
                right[i] = len - 1;
                myStackR.push(i);
            }

            else{
                while((!myStackR.empty()) && heights[myStackR.top()] >= heights[i]){
                    myStackR.pop();
                }
                right[i] = (myStackR.empty()) ? len - 1 : myStackR.top() - 1;
                myStackR.push(i);
            }    
        }

        int maxArea = 0;

        for(int i = 0; i < len; i++){
            int currArea = (right[i] - left[i] + 1) * heights[i];
            maxArea = max(currArea, maxArea);
        }

        return max(maxArea, maxm);
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
         int len = matrix[0].size();
        int maxRes = 0;
        vector<int>count(len);
        for(int i = 0; i < len; i++){
            count[i] = 0;
        }
        
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '1'){
                    count[j] += 1;
                }
                else{
                    count[j] = 0;
                }
            }
            
            maxRes = maxRect(count, maxRes);
        }
        
        return maxRes;
    }
};