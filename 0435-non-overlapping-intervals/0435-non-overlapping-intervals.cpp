class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int cnt = 0;
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            // int end = intervals[i-1][1];

            if(start < end) {
                cnt++;
                end = min(end, intervals[i][1]);
            }
            else{
                end = intervals[i][1];
            }
        }

        return cnt;
    }
};