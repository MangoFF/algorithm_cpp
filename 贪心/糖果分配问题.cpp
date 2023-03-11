#include <bits/stdc++.h>
using namespace std;
/*
一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一
个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果；所
有孩子至少要有一个糖果。求解最少需要多少个糖果。
*/

int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> children;
        int temp;
        for(int i=0;i<n;i++)
        {   cin>>temp;
            children.emplace_back(temp);
        }
        if(n<=1)
        {
            cout<<n<<endl;
            continue;
        }
        vector<int> candy(n,1);
        for(int i=1;i<n;i++)
        {
            if(children[i-1]<children[i])
            {
                candy[i]=candy[i-1]+1;
            }
        }
        for(int i=n-1;i>0;i--)
        {
            if(children[i-1]>children[i])
            {
                candy[i-1]=max(candy[i-1],candy[i]+1);
            }
        }
        cout<<accumulate(candy.begin(),candy.end(),0)<<endl;
    }
    return 1;
}