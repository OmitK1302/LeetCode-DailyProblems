class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        int carry = 0;
        for(int i = 0; i < 32; i++) {
            int first = (1 << i) & a;
            int sec = (1 << i) & b;

            if(first && sec) {
                if(carry == 1) {
                    res |= (1 << i);
                }
                else{
                    carry = 1;
                }
            }

            else if(!first && !sec) {
                if(carry == 1) {
                    res |= (1 << i);
                    carry = 0;
                }
            }

            else{
                if(!carry) {
                    res |= (1 << i);
                }
            }
        }


        return res;
    }
};