class Solution {
public:
    vector<int>res;
    int minDiff = INT_MAX;
    void helper(int n, int k, vector<int>& divs, vector<int>& curr, int i, int maxNum, int minNum) {
        if(i == divs.size()) return;

        if(k == 0) {
            // for(int& num : curr) {
            //     cout<<num<<" ";
            // }
            // cout<<" :::: "<<n<<" "<<minNum<<" "<<maxNum<<" "<<endl;
            // cout<<endl;
            if(n == 1 && maxNum - minNum < minDiff) {
                minDiff = maxNum - minNum;
                res = curr;
            }
            return;
        }

        if(n % divs[i] == 0) {
            curr.push_back(divs[i]);
            int temp1 = max(maxNum, divs[i]);
            int temp2 = min(minNum, divs[i]);
            helper(n/divs[i], k - 1, divs, curr, i, temp1, temp2);
            curr.pop_back();
        }

        helper(n, k, divs, curr, i+1, maxNum, minNum);
    }
    vector<int> minDifference(int n, int k) {
        vector<int>divs;
        for(int i = 1; i <= n; i++) {
            if(n % i == 0) {
                divs.push_back(i);
            }
        }

        vector<int>curr;
        helper(n, k, divs, curr, 0, 0, 1000000);
        return res;

        // cout<<divs.size();
        // return {};


    }
};