/*
Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/
// sth like
  int minimumTotal(vector<vector<int> > triangle) {
      int m = triangle.size();
      if (m == 0) {
          return 0;
      }
      int sum[triangle[m-1].size()];
      memset(sum, 0, triangle[m-1].size() * sizeof(int));
      
      for (int i = m - 1; i >= 0; i--) {
          for (int j = 0; j < triangle[i].size(); j++) {
              if (i == m - 1) {
                  sum[j] = triangle[i][j];
              } else {
                  sum[j] = triangle[i][j] + min(sum[j], sum[j+1]);
              }
          }
      }
      
      return sum[0];
  }
  
  done good!! thx, let me save it