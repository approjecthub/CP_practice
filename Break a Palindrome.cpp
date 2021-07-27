//https://leetcode.com/problems/break-a-palindrome/

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        
        if(n<=1){
            return "";
        }
        int i;
        for(i = 0; i<n; i++){
            if(palindrome[i]-'a'==0){
                continue;
            }
            else{
                if(n%2!=0){
                    if(n/2 == i){
                        continue;
                    }
                    else{
                        palindrome[i]='a';
                        break;
                    }
                }
                else{
                    palindrome[i]='a';
                    break;
                }
            }
        }
        
        if(i<n){
            return palindrome;
        }
        else{
            palindrome[i-1]++;
            return palindrome;
        }
    }
};
