class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);

        if(k == str.length()) {
            return 1;
        }

        // int curr = 0;
        // for(int i = 0; i < k; i++) {
        //     int num = str[i] - '0';
        //     curr = (curr * 10) + num;
        // }

        int res = 0;
        // if(num % curr == 0) {
        //     res++;
        // }

        for(int i = 0; i <= str.length() - k; i++) {
            // int temp = str[i] - '0';
            // curr = curr * 10 + temp;
            // if(num % curr == 0) {
            //     res++;
            // }

            string substr = str.substr(i, k);
            int temp = stoi(substr);

            if(temp != 0 && num % temp == 0) res++;
        }

        return res;
    }
};