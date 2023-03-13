#include <bits/stdc++.h>
using namespace std;
bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    dp[0][0] = true;
    for(int i=0; i<=m; i++){
        //每个i都要重新计算匹配值
        for(int j=1; j<=n; j++){
            //
            if(p[j-1] == '*'){
                //如果不匹配这个* 或者 直接跳过这个字符串
                //（因为*可以匹配人意的字符串，*可以直接匹配到0）
                dp[i][j] = dp[i][j-1] || (i>0 && dp[i-1][j]);
            }
            else{
                //字符匹配或者字符匹配？
                dp[i][j] = i>0 && dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='?');
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        bool res=isMatch(s1,s2);
        if(res)
        {
            cout<<"true"<<endl;
        }else
        {
            cout<<"false"<<endl;
        }
    }
}