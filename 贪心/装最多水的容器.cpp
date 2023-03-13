/*
给定一个长度为 n 的整数数组 height 。
有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。
*/
#include <bits/stdc++.h>
using namespace std;
//运用一个贪心遍历的思想，让复杂度编程了O（n）
//这种最多的一一般不是贪心就是动态规划
int maxArea(vector<int> &height)
{
    int n=height.size();
    int left=0,right=n-1;
    int res=0;
    while(left<right)
    {
        int area=min(height[left],height[right])*(right-left);
        if(height[left]<height[right])
        {
            left++;
        }else
        {
            right--;
        }
        res=max(res,area);
    }
    return res;
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
        cout<<maxArea(nums)<<endl;
    }
}