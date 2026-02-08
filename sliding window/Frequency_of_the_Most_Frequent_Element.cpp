// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

//sliding window approach
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size(), ans = 1,l=0;
        long long wsum = 0;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            wsum += nums[i];
            while(wsum+k<(long long)nums[i]*(i+1-l)){ 
                wsum -= nums[l];
                l++;
            }
            ans = max(ans,i+1-l);
        }
        return ans;
    }
};

//binary search approach
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size(), ans = 1;
        sort(nums.begin(), nums.end());
        
        vector<long long> prfx(n+1,0);
        for(int i=1; i<=n; i++){
            prfx[i] += nums[i-1]+prfx[i-1];
        }
        
        for(int i=1; i<n; i++){
            int l=0,r=i-1;
            while(l<=r){
                int mid = l + (r - l) / 2;
                if(prfx[i+1]-prfx[mid]+k>= (i-mid+1)*(prfx[i+1]-prfx[i])){
                    r = mid -1;
                    ans = max(ans, i-mid+1);
                }
                else{
                    l = mid + 1;
                }
            }
            
        }
        return ans;
    }
};