#include <bits/stdc++.h>
using namespace std;
int countEqulSubstr(string s)
{
    //因为一开始是两个字符，所以我们从1开始
    int cur=1,pre=0,count=0;
    int n=s.size();
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
        {
            cur++;
        }else
        {
            pre=cur;
            cur=1;
        }
        if(pre>=cur)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string s;
    while(cin>>s)
    {
        cout<<countEqulSubstr(s)<<endl;
    }
}