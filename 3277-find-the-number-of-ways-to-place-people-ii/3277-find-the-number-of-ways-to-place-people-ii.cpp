class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b [0];
        });

        int cnt = 0;
        for(int i = 0; i < points.size()-1; i++) {
            int top = points[i][1];
            int low = INT_MIN;
            for(int j = i+1; j < points.size(); j++) {
                if(points[j][1] <= top && points[j][1] > low) {
                    cnt++;
                    low = points[j][1];
                }
            }
        }

        return cnt;
    }
};