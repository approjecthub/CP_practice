//https://www.geeksforgeeks.org/counting-inversions/

long long int merge(long long arr[], long long l,long long mid, long long r){
    long long nl = (mid-l)+1;
    long long nr = (r-(mid+1)+1);
    long long left[nl];
    long long right[nr];
    
    long long i,j, ans=0,c1=0,c2=0;
    for(i=l; i<=mid;i++){
        left[c1++]= arr[i];
    }
    
    for(i=mid+1; i<=r;i++){
        right[c2++]= arr[i];
    }
    i=0;
    j=0;
    while(i<nl && j<nr ){
        if(left[i]<=right[j]){
            arr[l++] = left[i++];
            
        }
        else{
            ans += nl-i;
            arr[l++] = right[j++];
            
        }
    }
    
    while(i<nl){
        arr[l++] = left[i++];
    }
    while(j<nr){
        arr[l++] = right[j++];
        
    }
    return ans;
}

long long int mergeSort(long long arr[], long long i, long long j){
    long long int sum=0;
    if(i<j){
        long long mid = (i+j)/2;
        sum += mergeSort(arr,i, mid);
        sum += mergeSort(arr,mid+1, j);
        sum += merge(arr,i,mid,j);
    }
    return sum;
}
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr,0, N-1);
    }
