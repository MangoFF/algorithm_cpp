#include <bits/stdc++.h>
using namespace std;
bool cmp(string &s1,string &s2)
{
    int m=s1.size();
    int n=s2.size();
    //长度相等的区域    
    for(int i=0;i<min(m,n);i++)
    {
        if(s2[i]<s1[i])
        {
            return false;
        }
    }
    //不相等的区域，谁长谁大
    return m>=n;
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<string> s;
        string temp;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            s.emplace_back(temp);
        }
        sort(s.begin(),s.end(),cmp);
        for(int i=0;i<n;i++)
        {
            cout<<s[i]<<' ';
        }
        cout<<endl;
    }
}