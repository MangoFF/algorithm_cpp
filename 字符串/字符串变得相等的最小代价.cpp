#include <bits/stdc++.h>
using namespace std;
//我感觉这也是一个贪心的题目

int main()
{
    int n;
    string s1,s2;
    while(cin>>n>>s1>>s2)
    {
        vector<int> dp(26);
        for(int i=0;i<s1.size();i++)
        {
            dp[s1[i]-'a']++;
            dp[s2[i]-'a']--;
        }
        vector<int> more,less;
        for(int i=0;i<26;i++)
        {
            if(dp[i]>0)
            {
               more.push_back(i);
            }
            if(dp[i]<0)
            {
                less.push_back(i);
           }
        }
        //双指针
        int left=0;
        int res=0;
        //这里实质上是使用贪心算法，让大于0的跟尽可能近的小于0的匹配，这样算出来的代价最小（因为交换是没有代价的，所以我们只需要计算距离代价就可以了）
        for(int i=0;i<more.size();i++)
        {
            if(dp[more[i]]>-dp[less[left]])
            {
                dp[more[i]]+=dp[less[left]];
                res+=(abs(more[i]-less[left])*-dp[less[left]]);
                left++;
                i--;
                continue;
            }

            if(dp[more[i]]<-dp[less[left]])
            {
                dp[less[left]]+=dp[more[i]];
                res+=(abs(more[i]-less[left])*dp[more[i]]);
                continue;
            }
            res+=(abs(more[i]-less[left])*dp[more[i]]);
            left++;
        }
        cout<<res<<endl;
    }
}