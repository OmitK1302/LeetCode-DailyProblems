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

// O(n^3)
// class Solution {
// public:
//     int numberOfPairs(vector<vector<int>>& points) {
//         int res = 0;
//         sort(points.begin(), points.end());

//         for(int i = 0; i < points.size(); i++) {
//             vector<int>p1 = points[i];
//             for(int j = 0; j < points.size(); j++) {
//                 vector<int>p2 = points[j];
//                 bool isGood = true;

//                 if(i != j && p1[0] <= p2[0] && p1[1] >= p2[1]) {
//                     cout<<p1[0]<<" "<<p1[1]<<" "<<p2[0]<<" "<<p2[1]<<endl;
//                     for(int k = 0; k < points.size(); k++) {
//                         if(k != i && k != j) {
//                             vector<int>p3 = points[k];

//                             if(p3[0] >= p1[0] && p3[0] <= p2[0] && p3[1] <= p1[1] && p3[1] >= p2[1]) {
//                                 isGood = false;
//                                 break;
//                             }

//                         }
//                     }
//                     if(isGood) {
//                         res++;
//                     }
//                 }

//             }
//         }

//         return res;
//     }
// };