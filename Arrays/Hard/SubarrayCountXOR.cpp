// coding ninjas solution
#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int K)
{
    //    Write your code here.
    int x=0;
    int count=0;
    map<int,int> m;
    m[0]=1;
    int N=arr.size();
    for(int i=0;i<N;i++)
    {
        x=x^arr[i];
        
        int a=x^K;
        count+=m[a];
        m[x]++;
        
    }
    return count;
}