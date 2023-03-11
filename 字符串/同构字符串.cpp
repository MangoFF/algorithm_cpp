#include <bits/stdc++.h>
using namespace std;
/*
判断两个字符串是否同构。同构的定义是，可以通过把一个字符串的某些相同的字符转换成
另一些相同的字符，使得两个字符串相同，且两种不同的字符不能够被转换成同一种字符
*/

/*
这里把看起来非常复杂的概念变得如此清晰，也就说我上一次遇到同一个字符的
位置要想等，这样我们才可以采用一个字符替换另外一个字符，这似乎也是贪心的思想
*/
bool isIsomor(string s1,string s2)
{
    int n=s1.size(),m=s2.size();
    if(n!=m)
    {
        return false;
    }
    unordered_map<char,int> mp1,mp2;
    for(int i=0;i<n;i++)
    {
        if(mp1[s1[i]]!=mp2[s2[i]])
        {
            return false;
        }
        mp1[s1[i]]=i;
        mp2[s2[i]]=i;
    }
    return true;
}
int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        cout<<isIsomor(s1,s2)<<endl;
    }
}