#include "tool.h"
#include <bits/stdc++.h>
using namespace std;
/*
在一个 n * m 的二维数组中，每一行都按照从左到右 非递减 的顺序排序，每一列都按照从上到下 非递减 的顺序排序。
请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
        {
            return false;
        }
        int m=matrix.size();
        int n=matrix[0].size();
        int i=m-1,j=0;
        while(j<n&&i>=0)
        {
            if(target==matrix[i][j])
            {
                return true;
            }
            if(target>matrix[i][j])
            {
                j++;
            }else
            {
                i--;
            }
        }
        return false;

}
int main()
{
    auto mat=getRandom2D(20,20,true);
    bool find_it=findNumberIn2DArray(mat,50);
    if(find_it)
    {
        cout<<1;
    }else
    {
        cout<<0;
    }
    cout<<endl;
    return 1;
}