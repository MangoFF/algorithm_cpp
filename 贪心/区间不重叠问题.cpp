#include <bits/stdc++.h>
using namespace std;
/*
给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠.
//似乎这种最少的问题，不是贪心就是动态规划？
*/
int NoneOvermap(vector<vector<int>>& Interval);
int main()
{
    int n;
    while(cin>>n)
    {
        //变量存储Interval
        vector<vector<int>> Interval;
        //一个一个的放进去
        for(int i=0;i<n;i++)
        {
            int start,end;
            cin>>start>>end;
            Interval.emplace_back(vector<int>{start,end});
        }
        //输出答案
        cout<<NoneOvermap(Interval)<<endl;
    }
}
bool cmp(vector<int> &a,vector<int> &b)
{
    return a[1]<b[1];
}
//选取策略，我们对end进行排序，如果同样是占用一个位置，另外一个比这个占用的end更多，说明他一定不是最优方案，可以排除
//最后的最优方案就由这些次优方案组合起来了。
int NoneOvermap(vector<vector<int>>& Interval)
{
    //特殊情况，输入为空
    if(Interval.empty())
    {
        return 0;
    }
    //把必要的参数声明好
    int n=Interval.size();

    //排序
    /*写法一
    匿名函数直接写里面
    sort(Interval.begin(),Interval.end(),[](vector<int>&a,vector<int> &b)
    {
        return a[1]<b[1];
    });
    */
   
    /*写法二
    匿名函数些外面
   auto cmp=[](vector<int>&a,vector<int>&b)->bool {
    return a[1]<b[1];//表示递增
   };
   sort(Interval.begin(),Interval.end(),cmp);
    */

   /*写法三 
   外部声明/或者外部定义struct重构()也就是函数类
    sort(Interval.begin(),Interval.end(),cmp);
   */

    //采用方法三的思路
    sort(Interval.begin(),Interval.end(),cmp);
    int removed=0,pre=Interval[0][1];
    for(int i=1;i<n;i++)
    {
        //如果start比前一个的end小，说明这个选择远不如pre的选择，反而额外耗费了很多空间
        if(Interval[i][0]<pre)
        {
            removed++;
        }else
        {
            //如果不和前一个冲突，那么蜗居选这个并且记录他的end
            pre=Interval[i][1];
        }
    }
    return removed;
}