class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9 + 7;
        unordered_map<int ,int>mp1;
        unordered_map<int ,int>mp2;
        stack<int>st1;
        stack<int>st2;
        long long res = 0;
        int n = arr.size();
        vector<long long> helper(n, 1);

        // return 1;
        for(int i = 0; i < arr.size(); i++) {
            // cout<<arr[i]<<": ";
            while(!st1.empty() && st1.top() > arr[i]) {
                // cout<<st.top()<<" ";
                mp1.erase(st1.top());
                st1.pop();
            }
            while(!st2.empty() && st2.top() >= arr[n-i-1]) {
                // cout<<st.top()<<" ";
                mp2.erase(st2.top());
                st2.pop();
            }
            // cout<<endl;

            int left = 1;
            int right = 1;

            if(st1.empty()) {
                // res = (res + (i * arr[i])) % MOD;
                left = i+1;
            }
            else{
                // res = (res + ((i - mp[st.top()] - 1) * arr[i])) % MOD;
                left = i - mp1[st1.top()];
            }

            if(st2.empty()) {
                right = i + 1;
            }
            else{
                right = mp2[st2.top()] - (n - i - 1);
            }

            cout<<left<<" "<<right<<endl;
            // res += (left * right * arr)
            helper[i] *= left; 
            helper[n-i-1] *= right; 
            st1.push(arr[i]);
            mp1[arr[i]] = i;
            st2.push(arr[n-i-1]);
            mp2[arr[n-i-1]] = n-i-1;
        }


        for(int i = 0; i < helper.size(); i++) {
            cout<<helper[i]<<" ";
            res += ((helper[i] * arr[i]) % MOD);
        }
        return res % MOD;
    }
};