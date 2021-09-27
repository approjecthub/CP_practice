//https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int findPivot(vector<int> arr, int n){
        int s = 0, e = n-1, mid;
        if(arr[s]<arr[e]) return 0;
        while(s<e){
            mid = (s+e)/2;
            if(mid<n-1 && arr[mid]>arr[mid+1]){
                
                break;
            }
            if(arr[s]<=arr[mid] || arr[e]<=arr[mid] ){
                s = mid + 1;
            }
            else if (arr[e]>arr[mid] || arr[s] > arr[mid]){
                e = mid;
            }
        }
        return mid;
    }
    int bSearch(vector<int> arr, int s, int e, int x){
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]==x) return mid;
            else if(arr[mid]<x) s = mid+1;
            else e = mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums[0]<nums[n-1]){
            
            return bSearch(nums, 0, n-1, target); 
        }
        int pivot = findPivot(nums, n);
        
        if(nums[pivot]==target) return pivot;
        if (target<=nums[pivot] && target>=nums[0]){
            
          return bSearch(nums, 0, pivot, target);  
        } 
        else{
            return bSearch(nums, pivot+1, n-1, target); 
        }
    }
};
