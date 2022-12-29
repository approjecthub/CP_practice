// https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/24012150#learning-tools
//https://leetcode.com/problems/kth-largest-element-in-an-array/
//return kth smallest element in the array, distinct integers
#include <bits/stdc++.h>
using namespace std;

// ########################## sol1 #############################
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition (int arr[], int low, int high)
{
   int pivotIdx = high,i=low-1,j=low;
   
   while(j<high){
       if(arr[j]<arr[pivotIdx]){
           i++;
           swap(arr, i, j);
       }
       j++;
   }
   
   i++;
   swap(arr, i, pivotIdx);
   return i;
}
int quickSort(int arr[], int low, int high, int k)
{
    if(low<high){
        int loc = partition(arr, low, high);
        if(k>loc){
        return quickSort(arr, loc+1, high, k);
        }
        else if(k<loc){
        return quickSort(arr, low, loc-1, k);
        }
        else{
            return arr[k];
        }
    }
    else {
        if(low==k || high==k){
            return arr[k];
        }
        return -1;
    }
}

//################# sol2 ####################################
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