// GFG

class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int low=0;
	    int high=n-1;
	    int ans=INT_MAX;
	    int index;
	    int mi;
	    while(low<=high)
	    {
	        int mid=((low+high)/2);
	        if(arr[low]<=arr[mid])
	        {
	           mi=arr[low];
	           if(mi<=ans)
	           {
	               ans=mi;
	               index=low;
	           }
	            low=mid+1;
	        }
	        else
	        {
	           mi=arr[mid];
	           if(mi<=ans)
	           {
	               ans=mi;
	               index=mid;   
	           }
	            high=mid-1;
	        }
	    }
	    return index;
	}

};