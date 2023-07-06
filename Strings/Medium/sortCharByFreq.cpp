// leetcode
class Solution {

public:
    string frequencySort(string s) {
        int n=s.length();
        
        map<char,long long> m;
        string ans;
        for(int i=0;i<n;i++)
        {
            m[s[i]]++;
        }
        vector<pair<long long,char>> p;
        for(auto x: m)
        {
            p.push_back(make_pair(x.second,x.first));
        }
        sort(p.begin(),p.end());
        reverse(p.begin(),p.end());
        for(auto x: p)
        {
            long long count=x.first;
            while(count>0)
            {
                ans+=x.second;
                count--;
            }
        }
        return ans;

    }
};