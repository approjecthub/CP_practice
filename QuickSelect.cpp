//https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    static int partition(vector<int>& nums, int i, int j){
        
        int s=i-1,t;
        for(int l=i;l<j;l++){
            if(nums[l]<nums[j]){
                
                s++;
                t = nums[s];
                nums[s]= nums[l];
                nums[l] = t;
            }
        }
        
        s++;
        t = nums[s];
        nums[s]= nums[j];
        nums[j] = t;
        return s;
    }
    static int qs(vector<int>& nums, int i, int j, int k){
        if(i>=j){
            return nums[k];
        }
        else{
            int pivot = partition(nums,i,j);
            if(pivot == k) return nums[pivot];
            else if(k>pivot) return qs(nums, pivot+1, j, k);
            else return qs(nums, i, pivot-1, k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        //we have (n-k) smallest element
        int n = nums.size();
        k = n-k;
        return qs(nums, 0, n-1, k);
    }
};
