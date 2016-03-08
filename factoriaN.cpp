/*
求n!  twitter phone
*/

int calculate(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    
    int prod = 1;
    int prev = prod;
    int i = 1;
    while (i <= n) {
        prod = i * prev;
        prev = prod;
        i++;
    }
    return prod;
}