/*randomly return the index of maximal elements in the array. 
follow up: 要求linear time 和constant space 
 0  1  2  3  4  5  6
[5, 2, 5, 5, 3, 1, 5]
5是最大的数，但是要等概率的返回5的index, 每次调用这个函数的时候返回的index都可能不同，等概率的选择. fb*/

int findMax(vector<int> arr){
    int len = arr.size();
    int ret = -1;
    int max = -1;
    int count = 0;
    for (int i=0; i<len; i++){
        if (arr[i] == max){
            count++;
            int judge = rand()%(count+1); // judge in the range 0 to count
            if (judge == 0)    //也就是对于每一次扫到最大值的时候，都是从0到当前count中选取随机数就好了，
                //这样的话，就可以保证每次选取出来的值是相等概率的. 
                ret = i;
        }
        else if (max == -1 || arr[i] > max){
            max = arr[i];
            ret = i;
            count = 1;
        }
    }
    return ret;
}