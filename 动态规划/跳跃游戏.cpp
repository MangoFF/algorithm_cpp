#include <bits/stdc++.h>
using namespace std;
int minJump(vector<int> &nums)
{
    int n=nums.size();
    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        if(dp[i]!=INT_MAX)
        {
            for(int j=1;j<=nums[i]&&i+j<n;j++)
            {
                dp[i+j]=min(dp[i+j],dp[i]+1);
            }
        }
    }
    return dp[n-1];
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> nums(n);
        for(int i=0;i<n;i++)
        {
            cin>>nums[i];
        }
        cout<<minJump(nums)<<endl;
    }
}