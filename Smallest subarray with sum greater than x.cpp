class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here 
        int ans = n, sum=0,size=0,l=0;
        for (int i=0; i<n;i++){
            
                sum += arr[i];
                size++;
            if(sum>x){
                ans = min(ans, size);
                bool flag = false;
                while(sum>x){  
                size--;
                sum -= arr[l];
                l++;
                flag = true;
                }
                if(flag && (arr[l-1]+sum)>x){
                    
                    ans = min(ans, size+1);
                }
            
            }
        }
        
        return ans;
    }
};
