
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