// leetcode solution
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        // better solution using hashing
        int longest=0;
        int len=0;
        int sum=0;
        map<int,int> m;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
           
            if(sum==K)
            {
                len=i+1;
                longest=max(len,longest);        
            }
            else if(m.count(sum-K)!=0)
            {
                len=i-(m[sum-K]);
                longest=max(len,longest);
            }
            
           if (m.find(sum) == m.end()) {
            m[sum] = i;
        }
        }
        
        return longest;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends