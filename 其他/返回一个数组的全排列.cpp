#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    backtrack(nums,0,res);
}
void backtrack(vector<int>& nums,int i,vector<vector<int>>& res)
{
    if(i==nums.size()-1)
    {
        res.push_back(nums);
    }
    //i之后的所有元素都有可能被换到i位置，所以这种排列是全面的
    for(int j=i;j<nums.size();++j)
    {
        swap(nums[i],nums[j]);
        backtrack(nums,i+1,res);
        swap(nums[i],nums[j]);
    }

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
        auto res=permute(nums);
    }
}