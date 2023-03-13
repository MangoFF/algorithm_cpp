#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices)
{
    int n=prices.size();
    int profit=0;
    //这个就是典型的贪心思想，如果想要赚的钱最多，每次价格上涨的时候我都参与就好了
    for(int i=1;i<n;i++)
    {
        if(prices[i]>prices[i-1])
        {
            profit+=prices[i]-prices[i-1];
        }
    }
    return profit;
}
/*
上面的解法已经够好了，但是仍然存在一种动态规划的解法，计算任意时刻持有和不持有的最大利润
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //只有持有和未持有两个状态，我们动态规划一下就好了；
        int n=prices.size();
        int get=0,put=0;
        get=-prices[0];
        //构建两个状态可以相互转化，注意的是，最后的答案一定是不持有，因为持有的卖掉就会比不持有的高
        for(int i=1;i<n;i++)
        {
            //状态转化要么继续持有，要么从不持有转化成持有
            int cur=max(get,put-prices[i]);
            //状态转化 要么继续不持有，要么从持有变成不持有
            put=max(get+prices[i],put);
            get=cur;
        }
        return put;
    }
};
*/
int main()
{   
    int n;
    while(cin>>n)
    {
        vector<int> prices(n);
        for(int i=0;i<n;i++)
        {
            cin>>prices[i];
        }
        cout<<maxProfit(prices)<<endl;
    }
}