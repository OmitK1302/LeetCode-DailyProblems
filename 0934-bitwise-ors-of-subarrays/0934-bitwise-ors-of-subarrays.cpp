class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>prev;
        unordered_set<int>res;
        prev.insert(0);

        for(int& num : arr) {
            unordered_set<int>next;
            res.insert(num);
            next.insert(num);

            for(auto& curr : prev) {
                next.insert(curr | num);
                res.insert(curr | num);
                // next.insert(curr | num);
            }

            prev = next;
        }

        return res.size();
    }
};



/*
1 1 2



*/