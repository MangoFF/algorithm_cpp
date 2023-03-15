#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int string_to_num(string s)
{
    
}
int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 将序列按照从小到大排序
    sort(a, a + n);

    // 哈希表记录每个数出现的次数
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }

    // 初始化答案序列
    int ans = 0;

    // 贪心算法
    for (int i = 0; i < n; i++) {
        int num = a[i];

        // 如果当前数没有被删除
        if (count[num] > 0) {
            ans += num;
            count[num]--;

            // 删除相邻的数
            count[num - 1] = max(0, count[num - 1] - 1);
            count[num + 1] = max(0, count[num + 1] - 1);
        }
    }

    cout << ans << endl;
    return 0;
}
