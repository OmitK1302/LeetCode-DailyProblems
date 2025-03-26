class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<vector<int>> merged;
        merged.push_back(meetings[0]);
        int j = 0;
        for(int i = 1; i < meetings.size(); i++){
            if(merged[j][1] >= meetings[i][0]) {
                merged[j][0] = min(merged[j][0], meetings[i][0]);
                merged[j][1] = max(merged[j][1], meetings[i][1]);
            }
            else{
                merged.push_back(meetings[i]);
                j++;
            }
        }

        j = 0;
        int res = 0;
        for(int i = 1; i <= days; i++){
            if(i == merged[j][0]){
                i = merged[j++][1];
                if(j == merged.size()) {
                    return res + days - i; 
                }
            }
            else{
                res++;
            }
        }

        // int i = 1;
        // int res = 0;
        // for(vector<int>& meet : meetings){
        //     if(i != meet[0]){
        //         while(i < days && i < meet[0]){
        //             res++;
        //             i++;
        //         }
        //     }

        //     i = meet[1] + 1;
        // }

        return res;
    }
};