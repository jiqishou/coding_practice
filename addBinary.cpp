/*  Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". */

string addBinary(string s1, string s2) {
    int len1 = s1.size();
    int len2 = s2.size();
    int carry = 0, i = len1 - 1, j = len2 - 1;
    string res;
    while (i >= 0 || j >= 0) {
        int n1 = i >= 0 ? s1[i] - '0' : 0;
        int n2 = j >= 0 ? s2[j] - '0' : 0;
        int sum = n1 + n2 + carry;
        res = (sum % 2 + '0') + res;
        carry = sum / 2;
        i--;
        j--;
    }
    
    if (carry == 1) {
        res = '1' + res;
    }
    return res;
}