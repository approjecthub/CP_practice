//https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/24428776#overview

//similar with 2 pair sum
// done in TC: O(N), and in 1 pass
#include <bits/stdc++.h>

using namespace std;

pair<int, int> pairSum(vector<int> arr, int target){
    unordered_set<int> uset;
    int n = arr.size();
    for(int i=0;i<n; i++){
        if(uset.find(target - arr[i])!=uset.end()){
            return {arr[i],target - arr[i]};
        }
		uset.insert(arr[i]);
    }
    return {-1,-1};
}
int main()
{
    vector<int> arr = {10,5,2,3,-6,9,11};
    int target = 4;
    pair<int, int> p = pairSum(arr, target);
    cout<<p.first<<" : "<<p.second;//10,-6
    return 0;
}