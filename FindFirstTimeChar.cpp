/*
给一个string（只含小写字母），返回第一个只出现一次的char的index， 比如: ‘abacd’ 返回 1(‘b’), ‘ababcd’ 返回 4(‘c’) 
*/
//Amazon phone

int findFirstChar(string &str) {
    unordered_map<char, int> count;
    unordered_map<char, int> pos;
    
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        count[c]++;
        if (count[c] == 1) {
            pos[c] = i;
        }
    }
    
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (count[c] == 1) {
            return pos[c];
        }
    }
    
    return -1;
}