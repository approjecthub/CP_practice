//https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1#

vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int strt=0;
        vector<int> ans;
        long long temp = 0;
        for(int i=0; i<n; i++){
            if (temp<s){
                temp += arr[i];
            }
            
            while(temp> s && strt<n){
                temp -= arr[strt];
                strt ++;
            }
            
            if(temp==s){
                ans.push_back(strt+1);
                ans.push_back(i+1);
                return ans;
            }
        }
        ans.push_back(-1);
        return ans;
    }
