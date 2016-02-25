
/*
Given a list of words, find whether a new word is anagram of word in list  --from UBER
 */
 
 bool judgeAnagram(vector<string> words, string str) {
     unordered_set<string> mySet;
     
     for (int i = 0; i < words.size(); i++) {
         string tmp = words[i];
         sort(tmp.begin(), tmp.end());
         if (mySet.find(tmp) == mySet.end()) {
             mySet.insert(tmp);
         }
     }
     
     sort(str.begin(), str.end());
     if (mySet.find(str) == mySet.end()) {
         return false;
     } else {
         return true;
     }
 }
 Time Complexity: O(n * mlgm) where n is number of words and m is the average lengh of a word
 Space Complexity: O(n) 
 
 why there are 2 solutions different solution has different complexity. First one is made by first glance. But second one is better on space.
 let me cc good~~~~
 
 bool judgeAnagram(vector<string> words, string str) {
     sort(str.begin(), str.end());
     
     for (int i = 0; i < words.size(); i++) {
         string tmp = words[i];
         sort(tmp.begin(), tmp.end());
         if (tmp == str) {
             return true;
         }
     }
     
     return false;
 }
 Time Complexity: O(n * mlgm)
 Space Complexity: O(1) 
/*
Given a list of words, find whether a new word is anagram of word in list  --from UBER
 */
 
 bool judgeAnagram(vector<string> words, string str) {
     unordered_set<string> mySet;
     
     for (int i = 0; i < words.size(); i++) {
         string tmp = words[i];
         sort(tmp.begin(), tmp.end());
         if (mySet.find(tmp) == mySet.end()) {
             mySet.insert(tmp);
         }
     }
     
     sort(str.begin(), str.end());
     if (mySet.find(str) == mySet.end()) {
         return false;
     } else {
         return true;
     }
 }
 Time Complexity: O(n * mlgm) where n is number of words and m is the average lengh of a word
 Space Complexity: O(n) 
 
 why there are 2 solutions different solution has different complexity. First one is made by first glance. But second one is better on space.
 let me cc good~~~~
 
 bool judgeAnagram(vector<string> words, string str) {
     sort(str.begin(), str.end());
     
     for (int i = 0; i < words.size(); i++) {
         string tmp = words[i];
         sort(tmp.begin(), tmp.end());
         if (tmp == str) {
             return true;
         }
     }
     
     return false;
 }
 Time Complexity: O(n * mlgm)
 Space Complexity: O(1)
Position:   Ln 1, Ch 1  Total:  Ln 43, Ch 1166  
