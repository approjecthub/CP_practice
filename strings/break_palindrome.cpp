//https://leetcode.com/problems/break-a-palindrome/
#include <bits/stdc++.h>

using namespace std;
string breakPalindrome(string palindrome) {
    bool isDone = false;
    int n = palindrome.size();
    if(n==1) return "";
    for(int i=0; i<n; i++){
        
        if(palindrome[i]!= 'a' && n/2!=i){
            
            isDone = true;
            palindrome[i] = 'a';
            break;
        }
    }
    if(!isDone){
        palindrome[n-1]++;
    }
    return palindrome;
}

int main()
{
    cout<<breakPalindrome("aba");
    return 0;
}
