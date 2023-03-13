#include <bits/stdc++.h>
using namespace std;
//得到数字，顺位移动idx
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
//得到char idx移动
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
        //只要idx不越界
        for(;idx<n;)
        {
            //得到num和char
            int num=getNum(s,idx);
            char c=getChar(s,idx);
            //使用stirng num c来构造string ，然后使用+来拼接stirng
            res+=string(num,c);
        }
        cout<<res<<endl;
    }
}