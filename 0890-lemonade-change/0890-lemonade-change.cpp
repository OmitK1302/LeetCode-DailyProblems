class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change5 = 0;
        int change10 = 0;
        int change20 = 0;

        for(int& bill : bills) {
            if(bill == 5) {
                change5++;
            }
            if(bill == 10) {
                change10++;
                change5--;
                if(change5 < 0) return false;
            }
            if(bill == 20) {
                change20++;
                if(change10 > 0) {
                    change10--;
                    change5--;

                    if(change10 < 0 || change5 < 0) return false;
                }
                else{
                    change5 -= 3;
                    if(change5 < 0) return false;
                }
            }
            // if(curr >= 20) {
            //     int val = curr / 20;
            //     curr = curr % 20;
            //     change20 -= val;
            //     if(change20 < 0) return false;
            // }
            // if(curr >= 10) {
            //     int val = curr / 10;
            //     curr = curr % 10;
            //     change10 -= val;
            //     if(change10 < 0) return false;
            // }
            // if(curr >= 5) {
            //     int val = curr / 5;
            //     curr = curr % 5;
            //     change5 -= val;
            //     if(change5 < 0) return false;
            // }

            // if(bill == 5)change5++;
            // else if(bill == 10)change10++;
            // else if(bill == 20)change20++;

            // if(curr != 0) return false;

        }

        return true;
    }
};