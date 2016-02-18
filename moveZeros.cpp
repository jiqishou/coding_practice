/* Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations. */

void moveZeros(vector<int> &nums){
    int n = nums.size();
    
    int j=0;
    for (i=0; i<n; i++){
        if (nums[i] != 0){
            nums[j++] = num[i];  //still here? yep, let me cc, lost connection, ok, good
        }
    }

    for (;j<n; j++){
        nums[j] = 0;
    }
}
    /*int count = 0;
    
    int i=0;
    while(i<n-count){
        if (nums[i] == 0){
            for (int j=i; j<n-count-1; j++){
                nums[j] = nums[j+1];
            }
            count++;
        }
        else
            i++;
    }
    
    for (int j=n-1; j>n-count-1; j--){ // typo?
        nums[j] = 0;
    }*/
    

done ok, let me c. okay what's the time complexity O(n2) you mean O(n^2)? yes okay! good. did you see my optimization? I think it's O(n) now.

find a way to optimize it:
int j=0;
for (i=0; i<n; i++){
    if (nums[i] != 0){
        nums[j++] = num[i];
    }
}

for (;j<n; j++){
    nums[j] = 0;
}