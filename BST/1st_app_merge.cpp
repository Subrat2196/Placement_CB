class Solution{
public:
	void merge(int a1[], int a2[], int n, int m)
	{
	    
	    if(n==0 and m==0)
	    {
	        return;
	    }
	    
	   else if(n==0 and m!=0)
	    {
	        for(int i=0;i<m;i++)
	        {
	            cout<<a2[i]<<" ";
	        }
	        return;
	    }
	    
	   else if(n!=0 and m==0)
	    {
	        for(int i=0;i<n;i++)
	        {
	            cout<<a1[i]<<" ";
	        }
	        return;
	    }
	    
	    int i=0;
	    int j=0;
	    while(i<n)
	    {
	        if(a1[i]>a2[j])
	        {
	            swap(a1[i],a2[j]);
	            sort(a2,a2+m);
	        }
	        
	       // cout<<a1[i]<<" ";
	        i++;
	        
	    }
	    
	    // code here
	}
};