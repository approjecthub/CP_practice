
#include <iostream>

using namespace std;
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition (int arr[], int low, int high)
{
   // Your code here
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
void quickSort(int arr[], int low, int high)
{
    // code here
    if(low<high){
        int loc = partition(arr, low, high);
        quickSort(arr, low, loc-1);
        quickSort(arr, loc+1, high);
    }
    
}

int main()
{
   int n = 10;
   int arr[n] = {10 ,9 ,8 ,7 ,6, 5, 4 ,3 ,2, 1};
   quickSort(arr, 0, n-1);
   for(int i=0; i<n; i++){
       cout<<arr[i]<<",";
   }

    return 0;
}
