#include<bits/stdc++.h>
using namespace std;
//改出来了，我是天才
string minWindow(string s1,string s2)
{
    unordered_map<char,int> mp;
    int m=s1.size(),n=s2.size();
    for(int i=0;i<n;i++)
    {
        mp[s2[i]]--;
    }
    auto all_zero=[&]()->bool
    {
        for(auto &it:mp)
        {
            if(it.second<0)
            {
                return false;
            }
        }
        return true;
    };
    int l=0;
    int res=INT_MAX;
    string min_str;
    for(int i=0;i<m;i++)
    {
        if(mp.count(s1[i]))
        {
            mp[s1[i]]++;
            if(all_zero())
            {
                //一定要比原来的结果小我们才更新
                if(i-l+1<res)
                {
                    res=i-l+1;
                    min_str=s1.substr(l,res);;
                }
                while(l<i)
                {
                    if(mp.count(s1[l]))
                    {
                        mp[s1[l]]--;
                        if(mp[s1[l]]<0)
                        {
                            l++;
                            break;
                        }
                    }
                    l++;
                    //一定要比原来的结果小我们才更新
                    if(i-l+1<res)
                    {
                        res=i-l+1;
                        min_str=s1.substr(l,res);;
                    } 
                }
            }
        }else
        {
            continue;
        }
    }
    return min_str;
}

int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        cout<<minWindow(s1,s2)<<endl;
    }
}