/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
 */
 
 string findLongestPalindrome(string s){
     int n = s.size();
     if (n==0)
         return "";
     
     int maxL = 1;
     int start = 0;
     bool pal[n][n];   //pal[j][i] means from j to i, it is a valid palindromic substring
     memset(pal, false, n*n*sizeof(bool));  
     
     for (int i=0; i<n; i++){
         pal[i][i] = true;
     
         for (int j=0; j<i; j++){
            if ( (pal[j+1][i-1]||i==j+1) && s[i]==s[j] ){
                pal[j][i] = true;
            }
            
            if (pal[j][i] && i-j+1>maxL){
                maxL = i-j+1;
                start = j;
            }    
         }
     }
     
     return s.substr(start, maxL); // here is the second parameter exclusive or inclusive?inclusive
 }
 
here's the definition of substr:
The substring is the portion of the object that starts at character position pos and spans len characters 
(or until the end of the string, whichever comes first).