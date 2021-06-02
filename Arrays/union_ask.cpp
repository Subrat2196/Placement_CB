class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m) 
    {
        int c[m+n]={0};
        int i=0,j=0,k=0;
        while(i<n && j<m)
        {
            if(a[i]==b[j])
            {
                c[k]=a[i];
                i++;j++;k++;
            }
            else if(a[i]<b[j])
            {
                c[k]=a[i];
                i++;k++;
            }
            else
            {
                c[k]=b[j];
                k++;
                j++;
            }
        }
            while(i<n)
            {
                c[k]=a[i];
                k++;
                i++;
            }
            
        

            while(j<m)
            {
                c[k]=b[j];
                k++;
                j++;
            }
            
            
            count=sizeof(c)/sizeof(a[0]);
            cout<<count;
            
        
        
        //code here
    }
};
