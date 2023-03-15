#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
/*
有一个二进制串s，他想让这个二进制串异或上若干个长度相等且所有的1连续的二进制串 （如000111,1100,010,1等，但01010,101等不合法），使得s所有位都为0。小A想知道最少需要进行多少次异或运算？
输入描述
第一行一个正整数T，表示有T组数据；
接下来每一组数据对应一行，首先输入x，表示该二进制串长度;之后输入一个长度为x的二进制串。中间用空格隔开。
1≤×≤5×104 1sTs100
输出描述
输出T行，每一行一个整数，表示该数据下的最小异或次数
*/
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        stack<int> stk;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                if (stk.empty() || i - stk.top() > stk.top())
                {
                    stk.push(i);
                    ans++;
                }
                else
                {
                    stk.pop();
                    stk.push(i);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
