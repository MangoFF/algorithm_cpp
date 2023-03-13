#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
//在一个数据集合中寻找满足 x1<x2,y1<y2的最大数据集合
//使用动态规划是一个不错的解法，但是我没有找到比他更优的解法
//因为题目没法看答案，先这样吧
struct Data{
    int x;
    int y;
};
bool compareData(const Data& a, const Data& b) {
    if (a.x == b.x) {
        return a.y < b.y;
    } else {
        return a.x < b.x;
    }
}

int selectData( std::vector<Data>& arr) {
    int n = arr.size();
    
    std::sort(arr.begin(), arr.end(), compareData);
    int result = 1;
    //这是一个基于动态规划的解法
    std::vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j].x != arr[i].x && arr[j].y < arr[i].y) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        result = std::max(result, dp[i]);
    }
    return result;
    
}

int main() {
    int m, n;
    while (cin >> m ) { // 注意 while 处理多个 case
        vector<int> res;
        for(int k=0;k<m;k++)
        {
            cin>>n;
            vector<Data> nums(n);
            for(int i=0;i<n;i++)
            {
                cin>>nums[i].x;
            }
            for(int i=0;i<n;i++)
            {
                cin>>nums[i].y;
            }
            res.push_back(selectData(nums));   
        }
        for(int i=0;i<res.size()-1;i++)
        {
            cout<<res[i]<<' ';
        }
        cout<<res.back()<<endl;
    }
}
// 64 位输出请用 printf("%lld")