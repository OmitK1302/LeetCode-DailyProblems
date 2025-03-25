class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) 
    {
        vector<vector<int>>ans;
        int n = a.size();
        if(n==0)
            return ans;
        sort(a.begin(),a.end());
        // return a;
        ans.push_back(a[0]);
        int i,j=0;
        for(i=1;i<n;i++)
        {
            if(ans[j][1]<a[i][0])
            {
                ans.push_back(a[i]);
                j++;
            }
            else
            {
                ans[j][0]=min(ans[j][0],a[i][0]);
                ans[j][1]=max(ans[j][1],a[i][1]);
            }
        }
        return ans;
    }
};