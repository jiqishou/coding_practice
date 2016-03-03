/*
有个大小为n+1的数组，数组中的每个元素是[1,n]，所以至少有两个是重复的。例如n= 4, 数组为[2,3,4,1,1]或者[2,3,1,1,1]，
要求找出重复的那个数字。复杂度要求：空 间O(1), 时间复杂度：小于O(n^2)。 不能改变原来数组
 */

int findDuplicate(int nums[], int n) {
   int start = 1, end = n;
   int sum = 0;
   for (int i = 0; i <= n; i++) {
       sum += nums[i];
   }
   
   while (start + 1 < end) {
       int mid = start + (end - start) / 2;
       int count = 0;
       for (int i = 0; i <=n; i++) {
           if (nums[i] <= mid) {
               count++;
           }
       }
       if (count > (n + 1) / 2) {
           end = mid;
       } else {
           start = mid;
       }
   }

   int count = 0;
   for (int i = 0; i <= n; i++) {
       if (start == nums[i]) {
           count++;
       }
   }
   return count >= 2 ? start : end;
}

int main( void )
{
//vector<>
    int nums[8] = {1, 4, 7, 5, 3, 4 ,2, 6};
    int res = findDuplicate(nums, 7);
    printf("res is %d", res);
return 0;
}