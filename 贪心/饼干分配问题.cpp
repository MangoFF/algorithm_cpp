#include <bits/stdc++.h>
using namespace std;
/*
贪心算法的含义
保证每次操作都是局部最优的，从而使得最后的结果是全局最优的

有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干都有一个大小。每个孩子只能吃
一个饼干，且只有饼干的大小不小于孩子的饥饿度时，这个孩子才能吃饱。求解最多有多少孩子
可以吃饱。

这里的策略就是给剩余的孩子里面饥饿度最小的的孩子分配大于他但是最小的饼干
因为饥饿度最小的孩子最容易位宝
*/
int findContentChildren(vector<int> &children,vector<int> &cookies);
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        vector<int> child,cookie;
        int temp;
        for(int i=0;i<m;i++)
        {
            cin>>temp;
            child.emplace_back(temp);
        }
        for(int j=0;j<m;j++)
        {
            cin>>temp;
            cookie.emplace_back(temp);
        }
        cout<<findContentChildren(child,cookie)<<endl;
    }
}
int findContentChildren(vector<int> &children,vector<int> &cookies)
{
    sort(children.begin(),children.end());
    sort(cookies.begin(),cookies.end());
    int left=0,right=0;
    int m=children.size(),n=cookies.size();
    int res=0;
    while(left<m&&right<n)
    {
        if(children[left]<=cookies[right])
        {
            res++;
            left++;
            right++;
        }else
        {
            right++;
        }
    }
    return res;
}