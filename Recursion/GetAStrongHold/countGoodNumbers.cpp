// leetcode
#define mod 1000000007
class Solution {
    private:
    long long solve(long long n, long long x)
    {
        if(n==0) return 1;
        long long ans=solve(n/2,x);
        ans*=ans;
        ans%=mod;
        if(n%2==1)
        {
            ans*=x;
            ans%=mod;
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        long long even=n/2+n%2;
        long long odd=n/2;
        return (solve(even,5)*solve(odd,4))%mod;
    }
};