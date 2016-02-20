/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/

one question to clarify about neighbors, is the closest two elements are neighbors or all the others? neighbors
you mean the first option? two elements only? hmmmmm, i 

O(n) solution would be straightforward:

int findPeak(vector<int> nums){
    int n = nums.size();
    if (n==1)
        return 0;
    
    for (int i=0; i<n; i++){
        if (i==0 && nums[i]>nums[i+1])
            return 0;
        if (i==n-1 && nums[n-1]>nums[n-2])
            return n-1;
        
        if (nums[i]>nums[i-1] && nums[i]>nums[i+1])
            return i;
    }
    
    return -1;
}
done  ok, lets see. test case: {1} oka y, can you improve the time complexity

any hints for O(lgn) method? yeah, binary search

int findPeak(vector<int> nums){
    int n = nums.size();
    if (n==1)
        return 0;  // you don't need this now... anyway, it's good, yes
    
    int start = 0;
    int end = n-1;
    while (start<end){
        int mid = start + (end-start)/2;
        if (nums[mid] > nums[mid+1])
            end = mid;
        else 
            start = mid+1;
    }
    return start;
}
done ok,
somehow it's a little tricky to find this solution. spend too much time to deal with 0 and n-1 cases.