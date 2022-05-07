#include<bits/stdc++.h>
using namespace std;

void solve(string big,string small,vector<int> &ans, int prev){
    int pos = big.find(small,prev);
    if(pos == -1 ){
        return;
    }
    else{
        ans.push_back(pos);
        if(pos< big.size()){
        solve(big, small, ans, pos+1);
        }
    }
}
vector<int> stringSearch(string big,string small){
    vector<int> result;
    solve(big, small, result, 0);
    return result;
}