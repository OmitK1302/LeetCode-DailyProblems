class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        if(num1 == "0" || num2 == "0") return "0";

        int n = num1.length();
        int m = num2.length();
        string res((m+n), '0');
        int temp = 0;

        for(int i = 0; i < n; i++) {
            int n1 = num1[i] - '0';
            // cout<<n1<<" ";
            int carry = 0;

            for(int j = 0; j < m; j++) {
                int n2 = num2[j] - '0';
                int val = (n1 * n2) + carry + (res[j + temp] - '0');

                res[j + temp] = (val % 10) + '0';
                carry = val / 10;
                // cout<<j + temp<<" "<<res[j+temp]<<endl;
            }


            if(carry > 0) {
                res[m + temp] = carry + '0';
            }
            // cout<<res<<endl;

            temp++;
        }

        while(res.back() == '0') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};