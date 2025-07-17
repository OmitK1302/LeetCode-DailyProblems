class NumArray {
public:
    vector<int>seg;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n, 0);

        buildSeg(0, nums, 0, n-1);
    }
    
    void update(int index, int val) {
        updateSeg(index, val, 0, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return querySeg(left, right, 0, 0, n-1);
    }


    // Made functions:
    int buildSeg(int i, vector<int>& nums, int start, int end) {
        if(start == end) {
            seg[i] = nums[start];
            return seg[i];
        }

        int mid = (start + end) / 2;
        int ls = buildSeg(2*i + 1, nums, start, mid);
        int rs = buildSeg(2*i + 2, nums, mid + 1, end);

        return seg[i] = ls + rs;
    }

    void updateSeg(int indx, int val, int i, int start, int end) {
        if(start == end) {
            seg[i] = val;
            return;
        }

        int mid = (start + end) / 2;
        if(indx <= mid) {
            updateSeg(indx, val, 2*i + 1, start, mid);
        }
        else{
            updateSeg(indx, val, 2*i + 2, mid + 1, end);
        }

        seg[i] = seg[2*i + 1] + seg[2*i + 2];
    }

    int querySeg(int l, int r, int i, int start, int end) {
        if(start >= l && end <= r) {
            return seg[i];
        }
        else if(end < l || start > r) {
            return 0;
        }

        int mid = (start + end) / 2;

        return querySeg(l, r, 2*i + 1, start, mid) + querySeg(l, r, 2*i + 2, mid + 1, end);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */