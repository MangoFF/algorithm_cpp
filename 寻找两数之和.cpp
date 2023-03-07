#include "tool.h"
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