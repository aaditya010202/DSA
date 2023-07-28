// coding ninjas
#include <bits/stdc++.h> 

long long int solve(vector< int> &v)
{
    long long int prev=v[0];
    long long int prev2=0;
    long long int curr;
    long long int n=v.size();
    for(long long int i=1;i<n;i++)
    {
        long long int pick=v[i];
        if(i>1) pick+=prev2;
        long long int not_pick=0+prev;
        curr=max(pick,not_pick);

        prev2=prev;
        prev=curr;
    }
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    vector<int> temp1,temp2;
    long long int n=valueInHouse.size();
    if(n==1) return valueInHouse[0];
    for(long long int i=0;i<n;i++)
    {
        if(i!=0) temp1.push_back(valueInHouse[i]);
        if(i!=n-1) temp2.push_back(valueInHouse[i]);
    }
    long long int ans1=solve(temp1);
    long long int ans2=solve(temp2);

    return max(ans1,ans2);
}

