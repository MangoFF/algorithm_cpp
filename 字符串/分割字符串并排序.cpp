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
    return true;
}
vector<string> splitString(string &s)
{
    int n=s.size();
    vector<string> res;
    string temp;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=' ')
        {
            temp.push_back(s[i]);
        }else
        {
            res.push_back(temp);
            temp.clear();
        }
    }
    res.push_back(temp);
    return res;
}
int main()
{
    string s;
    while(getline(cin,s))
    {
        vector<string> strs=splitString(s);
        //其实这里都不用写一个排序，因为string默认的排序就是这个样子的
        sort(strs.begin(),strs.end(),cmp);
        for(int i=0;i<strs.size();i++)
        {
            cout<<strs[i]<<' ';
        }
        cout<<endl;
    }
}