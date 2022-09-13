// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1

int FindMaxSum(int arr[], int n)
{
    // Your code here
    // if(n<1) return 0;
    // else {
    //     return max(arr[n-1]+FindMaxSum(arr, n-2), FindMaxSum(arr, n-1));
    // }

    int currSum = 0, prev1 = 0, prev2 = 0;
    for (int i = 0; i < n; i++)
    {
        currSum = max(arr[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = currSum;
    }

    return currSum;
}