#include "tool.h"
#include <bits/stdc++.h>
using namespace std;
/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。
*/
/*
经典的双指针的问题，相向的指针，在一个排好序的数组中，增大前指针使结果变大，减小后指针使结果变小
从而达到减少搜索范围的目的
*/
vector<int> twoSum(vector<int> &nums,int target)
{
    vector<int> res;
    unordered_map<int,int> mp;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        if(mp.count(target-nums[i]))
        {
            return vector<int>{mp[target-nums[i]],i};
        }
        mp[nums[i]]=i;
    }
    return res;
}
int main()
{
    vector<int> example{2,7,11,15};
    auto result=twoSum(example,9);
    for(auto i:result)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}