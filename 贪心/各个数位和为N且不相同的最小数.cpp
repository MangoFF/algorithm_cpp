#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        string ans;
        for(int i=9;i>0;i--)
        {
            if(n>=i)
            {
                //string可以直接用+法来拼接
                ans+=to_string(i);
                n-=i;
            }
        }
        if(n>0)
        {
            cout<<-1<<endl;
            //输出之后记得continue，进入下一个数据
            continue;
        }
        //reverse是为了输出
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
}