/*
给一个array，生产一个新的array，新array中的每个元素都是输入array中除了这个位置之外其他的元素的乘积。
Linked Phone
*/

public int productExceptSelf(int[] nums) {
    int[] res = new int[nums.length];
    res[0] = 1;
    for (int i = 1; i < nums.length; i++) {
        res[i] = res[i - 1] * nums[i - 1];
    }
    int right = nums[nums.length - 1];
    for (int i = nums.length - 2; i >= 0; i--) {
        res[i] = res[i] * right;
        right *= nums[i];
    }
    return res;
}