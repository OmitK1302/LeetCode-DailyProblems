// class Solution {
// public:
//     int makeTheIntegerZero(int num1, int num2) {
//         if(num2 >= num1) {
//             return -1;
//         }

//         int val = num1 - num2;

//         long long temp = 1;
//         int res = 0;
//         for(int i = 31; i >= 0; i--) {
//             long long curr = (1 << i);


//             if(curr + num2 < num1 && curr != 0) {
//                 res += num1 / (curr + num2);
//                 num1 = num1 % (curr + num2);
//             }

//             if(num1 == 0) {
//                 return res;
//             }
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            long long x = num1 - 1LL * num2 * k;
            if (x < k) {
                return -1;
            }
            if (k >= __builtin_popcountll(x)) {
                return k;
            }
        }
        return -1;
    }
};