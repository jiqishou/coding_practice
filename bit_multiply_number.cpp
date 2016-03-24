/*
给定一个array:[3,7,5]---unique, primes,
求所有的可能的乘积

*/

vector<int> primeMultiply(vector<int> nums) {
    int len = nums.size();
    vector<int> res;
    unsigned long long bit = 1;
    unsigned long long bitmax = (1<<len);
    
    while (bit < bitmax) {
        unsigned long long curbit = bit;
        int product = 1;
        for (int i = 0; i < len; i++) {
            if (curbit & 1) {
                product *= nums[i];
            }
            curbit >>= 1;
        }
        res.push_back(product);
        bit++;
    }
    
    return res;
}