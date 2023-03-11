#include <bits/stdc++.h>
using namespace std;
/*
给定一个包含加减乘除整数运算的字符串，求其运算结果，只保留整数
*/

int calculate(string s) {
    vector<int> nums;
    int n=s.size();
    char preSign = '+';
    int num=0;
    for(int i=0;i<n;i++)
    {
        if(isdigit(s[i]))
        {
            num*=10;
            num+=(s[i]-'0');
        }
        if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) 
        {
            switch(preSign)
            {
                case '+': nums.push_back(num); break;
                case '-': nums.push_back(-num); break;
                case '*': nums.back()*=num; break;
                case '/': nums.back()/=num; break;
            }
            num=0;
            preSign=s[i];
        }
    }
    return accumulate(nums.begin(),nums.end(),0);
}

int main()
{
    string s;
    while(cin>>s)
    {
        cout<<calculate(s)<<endl;
    }
}