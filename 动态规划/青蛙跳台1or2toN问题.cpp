#include "tool.h"
#include <bits/stdc++.h>
using namespace std;
/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
*/
const int max_val=1e9+7;
//版本一 原始代码
int numWays(int n)
{
    vector<int> dp(n+1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=(dp[i-1]+dp[i-2])%max_val;
    }
    return dp[n];
}
//版本二 内存优化，滚动数组
int numWays2(int n)
{
    if(n<=1)
    {
        return 1;
    }
    int f1=0,f2=1,f3=1;
    for(int i=2;i<=n;i++)
    {
        f1=f2;
        f2=f3;
        f3=(f1+f2)%max_val;
    }
    return f3;
}

//版本3 迭代优化，变成矩阵幂的问题，然后用快速幂
vector<int> pow(int n)
{
    vector<vector<int>> res={{1,0},{0,1}};
    vector<vector<int>> mag={{1,0},{0,1}};
    auto mul=[&](vector<vector<int>> & a,vector<vector<int>> & b){
        vector<vector<int>> temp;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<1;j++)
            {
                temp[i][j]=(a[i][0]*b[0][j]+a[i][1]*b[1][j])%max_val;
            }
        }
        return temp;
    };
    while(n)
    {
        if((n&1)==1)
        {
            res=mul(res,mag);
        }
        mag=mul(mag,mag);
        n>>=1;
    }
    return res;
}
int numWays3(int n)
{
   
}
int main()
{
    int n=7;
    int res=numWays2(n);
    cout<<res<<endl;
    return 1;
}