//https://codeforces.com/contest/177/problem/D2
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, c;
    cin >> n >> m >> c;
    int a[n+1], b[m+1], pre[n+1] = {0}, a1[n+1];

    a[0] = 0, a1[0]=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a1[i] = a[i];
    }
    int l=1,r=n-m+2;
    for(int i=1;i<=m;i++){
        cin >> b[i];
        a1[l] =(a1[l]+ b[i]);
        l++;
        if(r<=n){
            //((a mod N) + (-b mod N)) mod N
            a1[r] =(a1[r] - b[i]);
            r++;
        }
    }
    

    for(int i=1;i<=n;i++){
        a1[i] =(a1[i]+ a1[i-1]);
        a[i] = (a[i]+ a[i-1]);
    }
    

    for(int i=1;i<=n;i++){
        cout<< (a1[i]-a[i-1])%c<<" ";
    }

    return 0;
    
}