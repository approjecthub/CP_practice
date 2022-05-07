//check there is a possible subsequence of s1 equals to s2

#include <bits/stdc++.h>

using namespace std;

bool isSubset(string s1, string s2){
    int n1 = s1.size() - 1;
    int n2 = s2.size() - 1;
    
    while(n1>=0 && n2>=0){
        if(s1[n1] == s2[n2]){
            n1--;
            n2--;
        }
        else{
            n1--;
        }
    }
    if(n2<0) return true;
    return false;
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    cout<<isSubset(s1, s2);
    return 0;
}
