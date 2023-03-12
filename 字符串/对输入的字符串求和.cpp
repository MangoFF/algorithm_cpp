#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        long int res=0;
        string temp;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                temp.push_back(s[i]);
            }else
            {
                res+=stoi(temp);
                temp.clear();
            }
        }
        res+=stoi(temp);
        cout<<res<<endl;
    }
}