class NumArray {
public:
    vector<int>seg;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n + 1, 0);

        buildTree(0, nums, 0, n-1);

        // for(int& num : seg) {
        //     cout<<num<<" ";
        // }
        // cout<<endl;
    }
    
    void update(int index, int val) {
        updateTree(index, val, 0, 0, n-1);

        // for(int& num : seg) {
        //     cout<<num<<" ";
        // }
        // cout<<endl;
    }
    
    int sumRange(int left, int right) {
        return query(left, right, 0, n-1, 0);
    }


    int buildTree(int i, vector<int>& nums, int start, int end) {
        if(start == end) {
            seg[i] = nums[start];
            return nums[start];
        }

        int mid = (start + end) / 2;
        int ls = buildTree(2*i + 1, nums, start, mid);
        int rs = buildTree(2*i + 2, nums, mid + 1, end);

        return seg[i] = ls + rs;
    }

    void updateTree(int indx, int val, int i, int start, int end) {
        if(start == end) {
            seg[i] = val;
            return;
        }
        int mid = (start + end) / 2;
        if(indx <= mid) {
            updateTree(indx, val, 2*i + 1, start, mid);
        }
        else{
            updateTree(indx, val, 2*i + 2, mid + 1, end);
        }

        seg[i] = seg[2*i + 1] + seg[2*i + 2];
    }

    int query(int l, int r, int start, int end, int i) {
        if(start >= l && end <= r) {
            return seg[i];
        }
        else if(l > end || r < start) {
            return 0;
        }
        int mid = (start + end) / 2;
        return query(l, r, start, mid, 2*i + 1) + query(l, r, mid + 1, end, 2*i + 2);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */