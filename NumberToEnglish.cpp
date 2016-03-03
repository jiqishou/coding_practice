/*
 Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 2^31 - 1

For example,

123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/
vector<string> oneNum {"", " ONE", " TWO", " THREE", " FOUR", " FIVE", " SIX", " SEVEN", " EIGHT", " NINE"};
    vector<string> twoNum {" TEN", " ELEVEN", " TWELVE", " THIRTEEN", " FOURTEEN", " FIFTEEN", " SIXTEEN", " SEVENTEEN", " EIGHTEEN", " NINETEEN"};
    vector<string> threeNum {"", "", " TWENTY", " THIRTY", " FOURTY", " FIFTY", " SIXTY", " SEVENTY", " EIGHTY", " NINETY"};

string EnglishWords(int num) {
    if (num == 0) {
        return "Zero";
    }
    
    int len = 0, n = num;
    while (n != 0) {
        n /= 10;
        len++;
    }
    string res = "";
    
    n = num;
    //billion
    if (len > 9) { 
        res += helper(n / 1000000000) + " BILLION";
    }
    n %= 1000000000;
    //million
    if (len > 6) {
        res += helper(n / 1000000) + " MILLION";
    }
    n %= 1000000;
    //thousand
    if (len > 3) {
        res += helper(n / 1000) + " THOUSAND";
    }
    n %= 1000;
    //left part to handle
    res += helper(n);
    
    return res;
}

string helper(int num) {
    int len = 0, n = num;
    string str = "";
    while (n != 0) {
        n /= 10;
        len++;
    }
    //hundred
    if (len == 3) {
        str += oneNum[n / 100] + " HUNDRED";
    }
    n %= 100;
    //two digits
    if (len >= 2) {
        if (n >= 20) {
            str += threeNum[n / 10];
        }
        else if (n > 10 && n < 20) {
            str += twoNum[n % 10];
            return str;
        }
    }
    n %= 10;
    //one digit
    str += oneNum[n];
    return str;
}