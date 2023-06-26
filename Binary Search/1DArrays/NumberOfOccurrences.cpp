// GFG

class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int low=0;
	    int high=n-1;
	    int floor=n;
	    while(low<=high)
	    {
	        int mid=((low+high)/2);
	        if(arr[mid]>=x)
	        {
	            floor=mid;
	            high=mid-1;
	        }
	        else{
	            low=mid+1;
	        }
	    }
	    
	    int ceil=n;
	    low=0;
	    high=n-1;
	    while(low<=high)
	    {
	        int mid=((low+high)/2);
	        if(arr[mid]>x)
	        {
	            ceil=mid;
	            high=mid-1;
	        }
	        else
	        {
	            low=mid+1;
	        }
	    }
	    return (ceil-floor);
	}
};