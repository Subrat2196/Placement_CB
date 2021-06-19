int minSwap(int *arr, int n, int k)
{
    //Here we need to apply the window technique 
    int count=0;  //here its count of elements less than equal to k
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=k)
            count++;
    }
    //Now we have the window size which is equal to 3
    //which is same as the number of elements <=3
    
    //Now we will calculate the minimum swaps value for the 1st three elements
    //which will be equal to the number of elements > k
    
    int swaps=0;  //c is swap counts
    for(int i=0;i<count;i++)
    {
        if(arr[i]>k)
            swaps++;
    }
    
    int result=swaps;
    
    int i=0,j=count;
    
    while(j<n)
    {
        if(arr[i]>k) swaps--;
        if(arr[j]>k) swaps++;
        
        result=min(result,swaps);
        i++;
        j++;
        
    }
    
    return result;
}
