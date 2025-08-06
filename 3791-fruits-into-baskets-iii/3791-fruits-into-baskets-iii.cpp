// class SGTree{
//     vector<int> seg;
// public:
//     SGTree(int n){
//         seg.resize(4*n+1);
//     }
//     void buildSeg(int ind, int low, int high, vector<int>& arr){
//         if(low == high){
//             seg[ind] = arr[low];
//             return;
//         }
//         int mid = (low + high)/2;
//         buildSeg(2*ind+1, low, mid, arr);
//         buildSeg(2*ind+2, mid+1, high, arr);
//         seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
//     }
    
//     int query(int ind, int low, int high, int l, int r){
//         //No Overlap -> (l,r) < (low,high) || (low,high) < (l,r)
//         if(r < low || l > high) return 0;
    
//         //Complete Overlap -> (l <= low && high <= r)
//         if(l <= low && high <= r) return seg[ind];
    
//         //Partial Overlap ->
//         int mid = (low + high)/2;
//         int left = query(2*ind+1, low, mid, l, r);
//         int right = query(2*ind+2, mid+1, high,l, r);
//         return max(left, right);
//     }
    
//     void update(int ind, int low, int high, int i, int val){
//         if(low == high){
//             seg[ind] = val;
//             return;
//         }
//         int mid = (low + high)/2;
//         if(i <= mid) update(2*ind+1, low, mid, i, val);
//         else update(2*ind+2, mid+1, high, i, val);
//         seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
//     }
// };



// class Solution {
//     int res = 0;
//     void find(int val, SGTree& seg, int n){
//         int indx = -1;
//         int low = 0, high = n-1;
//         while(low <= high){
//             int mid = (low + high)/2;
//             int mx = seg.query(0, 0, n-1, 0 , mid);

//             if(mx >= val){
//                 indx = mid;
//                 high = mid - 1;
//             }
//             else{
//                 low = mid + 1;
//             }
//         }
//         if(indx != -1){
//             seg.update(0, 0, n-1, indx, 0);
//         }
//         else{
//             res++;
//         }
//         return;
//     }
// public:
//     int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
//         int n = fruits.size();
//         SGTree seg(n);
//         seg.buildSeg(0, 0, n-1, baskets);
//         for(int i = 0; i < n; i++){
//             find(fruits[i], seg, n);
//         }
//         return res;
//     }
// };

class SGTree {
    vector<int>seg;
public:
    SGTree(int n) {
        seg.resize(4*n+1);
    }

    int buildSeg(int start, int end, int i, vector<int>& nums) {
        if(start == end) {
            seg[i] = nums[start];
            return seg[i];
        }

        int mid = (start + end) / 2;
        int ls = buildSeg(start, mid, 2*i + 1, nums);
        int rs = buildSeg(mid + 1, end, 2*i + 2, nums);

        return seg[i] = max(ls, rs);
    }

    int query(int start, int end, int i, int l, int r) {
        // full overlap
        if (start >= l && end <= r) {
            return seg[i];
        }

        // no overlap
        if (end < l || start > r) {
            return INT_MIN;  // for max query
        }

        // partial overlap
        int mid = (start + end) / 2;
        int ls = query(start, mid, 2 * i + 1, l, r);
        int rs = query(mid + 1, end, 2 * i + 2, l, r);
        return max(ls, rs);
    }


    void update(int start, int end, int indx, int val, int i) {
        if(start == end) {
            seg[i] = val;
            return;
        }

        int mid = (start + end) / 2;
        if(indx <= mid) {
            update(start, mid, indx, val, 2*i + 1);
        }
        else{
            update(mid + 1, end, indx, val, 2*i + 2);
        }

        seg[i] = max(seg[2*i + 1], seg[2*i + 2]);
    }

};



class Solution {
    int cnt = 0;
public:
    // Here we need to find the leftmost basket that can hold the fruit;
    // For that we fist find the mid value and find the maximum value in the range and then check if fruits can be placed in the basket or not.
    void bSearch(vector<int>& basket, int fruit, SGTree& seg) {
        int n = basket.size();
        int r = n-1;
        int l = 0;
        int indx = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int mxVal = seg.query(0, n-1, 0, 0, mid);

            if(mxVal >= fruit) {
                indx = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
            
        }

        if(indx != -1) {
            basket[indx] = -1;
            seg.update(0, n-1, indx, INT_MIN, 0);
        }
        else{
            cnt++;
        }
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        SGTree seg(n);
        seg.buildSeg(0, n-1, 0, baskets);
        for(int& val : fruits) {
            bSearch(baskets, val, seg);
        }

        return cnt;
    }
};