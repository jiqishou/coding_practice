/*
 Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT. 
*/

int divide(int n1, int n2) {
    if (n2 == 0) {
        return INT_MAX;
    }
    
    int sign;
    if (n1 > 0 && n2 > 0 || n1 < 0 && n2 < 0) {
        sign = 1;
    } else {
        sign = -1;
    }
    int count = 1;
    int num = abs(n2);
    while (num <= abs(n1)) {
        num = num << 1;
        count = count << 1;
    }

    while (num > abs(n1)) {
        num -= abs(n2);
        count--;
    }

    count = sign > 0 ? count : -count;
    return count;
    
   /* while (num <= abs(n1)) {
        num += abs(n2);
        count++;
    }
    return sign * count;*/
}