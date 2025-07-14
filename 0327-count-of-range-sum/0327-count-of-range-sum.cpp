#define ll long long
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset <ll> mpp;
        mpp.insert(0);
        ll sum=0,ans=0;
        for(ll i=0;i<nums.size();i++)
        {
            ll low,high;
            sum+=nums[i];
            low=sum-upper;
            high=sum-lower;
            auto lb=mpp.lower_bound(low);
            auto ub=mpp.upper_bound(high);
            ans+= distance(lb,ub);
            mpp.insert(sum);
        }
        return ans;
    }
};