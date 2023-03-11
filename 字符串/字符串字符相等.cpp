#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        if(s1.size()!=s2.size())
        {
            cout<<false<<endl;
            continue;
        }
        int n=s1.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[s1[i]]++;
            mp[s2[i]]--;
        }
        for(auto &it:mp)
        {
            int num=it.second;
            if(num!=0)
            {
                cout<<false;
                continue;
            }
        }
        cout<<true<<endl;
    }
}