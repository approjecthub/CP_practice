// https://www.interviewbit.com/problems/meeting-rooms/

#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> a, vector<int> b){
    return a[0]<b[0];
}

class RoomComp{
public:
bool operator()(vector<int> a, vector<int> b){
    return a[1]>b[1];
}
};

int solve(vector<vector<int> > &arr) {
sort(arr.begin(), arr.end(), comp);
// for(auto it:arr){
//     cout<<it[0]<<","<<it[1]<<endl;
// }
priority_queue<vector<int>, vector<vector<int> >, RoomComp>pq;
int ans = 1, i=0, n=arr.size();
if(n==0) return 0;
while(i<n){
    // cout<<"arr[i] : "<<arr[i][0]<<","<<arr[i][1]<<endl;
    // if(pq.size()>0){
    // cout<<"pqTop : "<<(pq.top()[0])<<","<<(pq.top()[1])<<endl;
    // }
    // cout<<(pq.size())<<endl;
    
    while(pq.size()>0 && pq.top()[1]<=arr[i][0]){
        pq.pop();
    }
    pq.push(arr[i]);
    // cout<<pq.size()<<endl;
    int tc = pq.size();
    ans = max(ans, tc);
    i++;
}
int tc = pq.size();
ans = max(ans, tc);
// cout<<"done"<<endl;
return ans;
}