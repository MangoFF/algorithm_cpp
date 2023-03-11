#include <bits/stdc++.h>
using namespace std;
//这种优雅的写法让我们不用考虑那一个先结束的问题
//但是这样相当于是遍历了两遍，可能也没我之前那种写法节约时间
int extendSubstr(string s,int l,int r)
{
    int count=0;
    while(l>=0&&r<=s.size()-1&&s[l]==s[r])
    {
        l--;
        r++;
        count++;
    }
    return count;
}
int PalindorSubstring(string s)
{
    int res=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        //之前那种写法确实是非常不优雅我们换一种优雅的写法
        res+=extendSubstr(s,i,i);
        res+=extendSubstr(s,i,i+1);
    }
    return res;
}

int main()
{
    string s;
    while(cin>>s)
    {
        cout<<PalindorSubstring(s)<<endl;
    }
}