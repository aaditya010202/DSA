// leetcode
class Solution {
public:
    int myAtoi(string s) {
        double ans=0;
        int n=s.size();
        long long i=0;
        while(s[i]==' ')
        {
            i++;
        }

        bool positive=false,negative=false;

        if(s[i]=='+')
        {
            positive=true;
            i++;
        }
        else if(s[i]=='-')
        {
            negative=true;
            i++;
        }

        while(i<n && s[i]>='0' && s[i]<='9')
        {
            ans=ans*10+(s[i]-'0');
            cout<<ans<<endl;
            i++;
        }

        if(negative) ans=-ans;

        if(ans>INT_MAX) ans=INT_MAX;
        else if(ans<INT_MIN) ans=INT_MIN;

        return (int)ans;
    }
};