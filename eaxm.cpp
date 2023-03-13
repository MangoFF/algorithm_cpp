#include <bits/stdc++.h>
using namespace std;
int getNum(string &s,int &idx)
{
    string num;
    for(;idx<s.size();idx++)
    {
        if(isdigit(s[idx]))
        {
            num+=s[idx];
        }else
        {
            break;
        }
    }
    return stoi(num);
}
char getChar(string &s,int &idx)
{
     char c=s[idx++];
     return c;
}
int main()
{
    string s;
    while(cin>>s)
    {
        string res;
        int idx=0,n=s.size();
        for(;idx<n;)
        {
            int num=getNum(s,idx);
            char c=getChar(s,idx);
            res+=string(num,c);
        }
        cout<<res<<endl;
    }
}