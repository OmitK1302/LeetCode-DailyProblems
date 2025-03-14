class Solution {
public:
    long long totalCandies(vector<int> &candies, int mid){
        long long total = 0;
        for(int i = 0;i<candies.size();i++)
            total += candies[i]/mid;
        return total;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int maxi = *max_element(candies.begin(), candies.end());
        int low = 1, high = maxi, mid;
        long long total;
        while(low <= high){
            mid = (low + high)/2;
            total = totalCandies(candies, mid);
            if(total<k)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return high;
    }
};