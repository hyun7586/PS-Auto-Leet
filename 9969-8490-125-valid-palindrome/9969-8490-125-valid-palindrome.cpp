#include <bits/stdc++.h>

class Solution {
public:
    bool isPalindrome(string s) {

        // make str
        string str="";
        for(int i=s.size()-1;i>=0;i--){
            int ascii = (int)s[i];

            if(97<=ascii && ascii <=122){
                str+=s[i];
            } else if(65 <=ascii && ascii <=90){
                str+=tolower(s[i]);
            } else if(48 <= ascii && ascii <=57){
                str+=s[i];
            } else{
                continue;
            }
        }

        // check if it is a valid palindrome
        int i=0, j=str.size()-1;
        bool isPalind=true;

        while(i<j){
            if(str[i]!=str[j]){
                isPalind=false;
                break;
            }

            i+=1;   j-=1;
        }

        return isPalind;
    }
};