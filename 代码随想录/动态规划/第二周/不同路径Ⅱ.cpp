//
// Created by admin on 2023/5/15.
//考虑障碍情况，初始化0行0列过程中遇到障碍则无需向后初始化，反正走不到，默认为0

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if(obstacleGrid[0][0] == 1 && obstacleGrid[m-1][n-1] == 0){
        return 0;
    }
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i = 0; i < m && obstacleGrid[i][0] == 0; i++){
        dp[i][0] = 1;
    }
    for(int j = 0; j < n && obstacleGrid[0][j] == 0; j++){
        dp[0][j] = 1;
    }

    for(int i = 1;i < m; i++){
        for(int j = 1;j < n; j++){
            if(obstacleGrid[i][j] == 1) continue;
            dp[i][j] = dp[i-1][j] +dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}