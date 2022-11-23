#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int min(int a, int b)
{
    return a < b ? a : b;
}


/*
    简单的一维DP：
    问题描述：一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法
*/
int f1(int n)
{
    int dp[n+1];
    dp[0]=0, dp[1]=1, dp[2]=2;
    for(int i=3; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

/*
问题描述
    一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
    机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
    问总共有多少条不同的路径？
*/
int f2(int m, int n)
{
    if(m <= 0 || n <= 0)
        return 0;

    int dp[m][n];
    for(int i = 0; i < n; i++)
        dp[0][i] = 1;
    for(int i = 0; i < m; i++)
        dp[i][0] = 1;
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
    
    return dp[m-1][n-1];
}

/*
问题三：最优路径和
*/
int f3(int** grid, int gridSize, int* gridColSize){
    int m = gridSize;
    int n = gridColSize[0];

    if(m <= 0 || n <= 0)
        return 0;

    int dp[m][n];
    dp[0][0] = grid[0][0];
    for(int i=1; i<n; i++)
        dp[0][i] = dp[0][i-1] + grid[0][i];
    for(int i=1; i<m; i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = min(dp[i-1][j]+grid[i][j], dp[i][j-1]+grid[i][j]);
    
    return dp[m-1][n-1];
}

/*
**问题描述**

给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：

- 删除一个字符
- 替换一个字符
- 插入一个字符
*/
int f4(char * word1, char * word2)
{
    int m = strlen(word1), n = strlen(word2);

    if(n*m == 0)
        return n+m;

    int dp[m+1][n+1];
    dp[0][0] = 0;
    for(int i = 1; i < m+1; i++)
        dp[i][0] = dp[i-1][0] + 1;
    for(int j = 1; j < n+1; j++)
        dp[0][j] = dp[0][j-1] + 1;

    for(int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if (word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
        }
    }

    return dp[m][n];
}

void main()
{
    // 问题一
    printf("%d\n", f1(5));

    // 问题二
    printf("%d\n", f2(5, 4));

    char word1[] = "horse";
    char word2[] = "ros";
    printf("%d\n", f4(word1, word2));
}