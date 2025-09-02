// class Solution {
// public:
//     int numberOfPairs(vector<vector<int>>& points) {
//         int res = 0;
//         // sort(points.begin(), points.end());
//         if(points.size() == 2 && ((points[0][0] <= points[1][0] && points[0][1] >= points[1][1]) || (points[1][0] <= points[0][0] && points[1][1] >= points[0][1])) ) return 1;

//         for(int i = 0; i < points.size()-1; i++) {
//             vector<int>p1 = points[i];
//             for(int j = 0; j < points.size(); j++) {
//                 vector<int>p2 = points[j];
//                 bool isGood = true;

//                 if(j != i && p1[0] <= p2[0] && p1[1] >= p2[1]) {

//                     for(int k = 0; k < points.size(); k++) {
//                         if(k != i && k != j) {
//                             if(points[k][0] >= p1[0] && points[k][0] <= p2[0] && points[k][1] <= p1[1] && points[k][1] >= p2[1]) {
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


class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int res = 0;
        sort(points.begin(), points.end());

        for(int i = 0; i < points.size(); i++) {
            vector<int>p1 = points[i];
            for(int j = 0; j < points.size(); j++) {
                vector<int>p2 = points[j];
                bool isGood = true;

                if(i != j && p1[0] <= p2[0] && p1[1] >= p2[1]) {
                    cout<<p1[0]<<" "<<p1[1]<<" "<<p2[0]<<" "<<p2[1]<<endl;
                    // bool left = p1[0] <= p2[0] ? true : false;
                    // cout<<left<<endl;
                    // bool left = 1 < 2;
                    for(int k = 0; k < points.size(); k++) {
                        if(k != i && k != j) {
                            vector<int>p3 = points[k];

                            if(p3[0] >= p1[0] && p3[0] <= p2[0] && p3[1] <= p1[1] && p3[1] >= p2[1]) {
                                // cout<<p3[0]<<" "<<p3[1]<<endl;
                                isGood = false;
                                break;
                            }



                            // if((left) && (points[k][0] >= points[i][0] && points[k][0] <= points[j][0] && points[k][1] >= points[i][1] && points[k][1] <= points[j][1])) {
                            //     isGood = false;
                            //     break;
                            // }
                            // if(!(left) && (points[k][0] >= points[j][0] && points[k][0] <= points[i][0] && points[k][1] >= points[j][1] && points[k][1] <= points[i][1])) {
                            //     isGood = false;
                            //     break;
                            // }

                        }
                    }
                    if(isGood) {
                        // cout<<i<<" "<<j<<endl;
                        res++;
                    }
                }

            }
        }

        return res;
    }
};