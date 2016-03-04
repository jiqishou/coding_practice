/*
Given an integer array, find a subarray with sum closest to zero. Return the indexes of the first number and last number.

Given [-3, 1, 1, -3, 5], return [0, 2], [1, 3], [1, 1], [2, 2] or [0, 4].

*/

public int[] subarraySumClosest(int[] nums) {
    int[] sum = new int[nums.length + 1];
    sum[0] = 0; 
    int left = 0;
    int right = 0;
    int closet = Integer.MAX_VALUE;
    for (int i = 1; i < sum.length; i++) {
        if (nums[i - 1] == 0) {
            return new int[]{i - 1, i - 1};
        }
        sum[i] += sum[i - 1] + nums[i - 1];
        if (sum[i] == 0) {
            return new int[]{0, i - 1};        
        }
        int abs = Math.abs(sum[i]);
        if (abs < closet) {
            closet = abs;
            left = 0;
            right = i - 1;
        }
    }
    
    for (int i = 1; i < sum.length - 2; i++) {
        for (int j = i + 2; j < sum.length; j++) {
            int rangeSum = sum[j] - sum[i];
            if (rangeSum == 0) {
                return new int[]{i - 1, j - 1};
            }
            int abs = Math.abs(rangeSum);
            if (abs < closet) {
                closet = abs;
                left = i - 1;
                right = j - 1;
            }
        }
    }
    return new int[]{left, right};
  }