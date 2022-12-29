//https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/24012280#learning-tools
//https://www.geeksforgeeks.org/place-k-elements-such-that-minimum-distance-is-maximized/
//TC: O(nlogn)

#include <bits/stdc++.h>

using namespace std;

bool isValidDistance(vector<int> &nests,int birds, int dis){
    int n = nests.size();
    int count = 1, curr_pos = nests[0]; 
    for(int i =1; i<n; i++){
        // cout<<nests[i]<<","<<curr_pos<<","<<dis<<endl;
        if(nests[i]>= curr_pos+dis){
            curr_pos = nests[i];
            count++;
        }
    }
    return count>=birds;
}

int getMinmLongestDistance(vector<int> &nests, int birds){
    int n = nests.size();
    int closestNest = INT_MAX;
    int farthestNest = INT_MIN;
    sort(nests.begin(), nests.end());
    
    int l = 0, r=nests[n-1]-nests[0], ans = -1;
    
    while(l<=r){
        int mid = l + (r-l)/2;
        if(isValidDistance(nests, birds, mid)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    
    return ans;
}

int main()
{
    vector<int> nests = {1,2,4,8,9};
    int birds = 3;
    cout<<getMinmLongestDistance(nests, birds);
    return 0;
}