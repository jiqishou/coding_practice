/*  给一排房子，用RGB三种颜色染色，相邻不能染成同色，每个房子染对应颜色会有对应的weight（W[N [3]），求最大的weight和 */

int maxWeight(vector<vector<int> > weight) {
    int n = weight.size();
    vector<vector<int> > maxW(n, vector<int>(3, 0));
    for (int j = 0; j < 3; j++) {
        dp[0][j] = weight[0][j];
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int tmpMax = 0;
            for (int m = 0; m < 3;m++) {
                if (m == j) {
                    continue;
                } else {
                    tmpMax = max(dp[i - 1][m], tmpMax);
                }
            }
            dp[i][j] = tmpMax + weight[i][j];
        }
    }
    
    int retMax = 0;
    for (int j = 0; j < 3; j++) {
        retMax = max(retMax, dp[n - 1][j];
    }
    return retMax;
}