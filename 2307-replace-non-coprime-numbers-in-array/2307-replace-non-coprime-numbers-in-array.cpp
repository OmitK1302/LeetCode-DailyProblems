class Solution {
public:
    int GCD(int x, int y) {
        if(x == y) return x;
        if(x > y) return GCD(x-y, y);
        return GCD(x, y-x);
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long>st;
        for(auto& it : nums) {
            long long x = it;
            while(!st.empty()) {
                long long curr = st.top();
                int currGcd = GCD(curr, x);
                if(currGcd > 1) {
                    st.pop();
                    x = (curr * x) / currGcd;
                    // st.push((curr * it) / currGcd);
                }
                else{
                    break;
                }
            }
            st.push(x);
            // if(st.empty()) {
            //     st.push(it);
            // }
            // else{
            //     long long curr = st.top();
            //     int currGcd = GCD(curr, it);
            //     if(currGcd > 1) {
            //         st.pop();
            //         st.push((curr * it) / currGcd);
            //     }
            //     else{
            //         st.push(it);
            //     }
            // }
        }

        vector<int>res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};