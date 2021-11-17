//https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution {
public:
    static bool customComp(vector<int> a, vector<int>b){
        if(a[1]<b[1]){          
            return true;
        }
        else if(a[1]==b[1]){
            return a[1]<b[0];
        }
        else{
            return false;
        }
    }
//     int findLongestChain(vector<vector<int>>& pairs) {
//         sort(pairs.begin(), pairs.end(), customComp);
//         int n = pairs.size();
//         int ans = 1;
//         for(int i=0;i<n;i++){
//             int t = pairs[i][1];
//             int c = 1;
//             for (int j=0; j<n;j++){
//                 if(pairs[j][0] > t){
//                     c++;
//                     t = pairs[j][1];
//                 }
//             }
//             ans = max(ans, c);
//         }
//         return ans;
//     }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), customComp);
        int n = pairs.size();
        int ans = 0;
        int curr = INT_MIN;
        
        for(int i=0; i<n;i++){
            if(pairs[i][0]>curr){
                ans++;
                curr = pairs[i][1];
            }
        }
        return ans;
    }
};
