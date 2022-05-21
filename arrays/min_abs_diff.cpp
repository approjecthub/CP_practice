// https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/quiz/5209708#overview
//https://www.geeksforgeeks.org/smallest-difference-pair-values-two-unsorted-arrays/
#include <bits/stdc++.h>

using namespace std;

pair<int,int> minDifference(vector<int> a,vector<int> b){
   
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int n1 = a.size(), n2 = b.size(), i=0,j=0, minDiff = INT_MAX;
    pair<int, int> ans = {-1,-1};
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            if(b[j]-a[i] < minDiff){
             ans.first = a[i];
             ans.second = b[j];
            minDiff = b[j]-a[i];
            }
            
            i++;
        }
        else{
            if(a[i]-b[j] < minDiff){
             ans.first = a[i];
             ans.second = b[j];
            minDiff = a[i]-b[j];
            }
            
            j++;
        }
    }
    
    return ans;
}