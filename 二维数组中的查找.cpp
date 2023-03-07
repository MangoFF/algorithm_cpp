#include "tool.h"

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
        {
            return false;
        }
        //如果不为空至少有一行
        int m=matrix.size(),n=matrix[0].size();
        int i=0,j=n-1;
        while(i<=m-1&&j>=0)
        {
            if(target==matrix[i][j])
            {
                return true;
            }
            if(target>matrix[i][j])
            {
                i++;
            }else
            {
                j--;
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