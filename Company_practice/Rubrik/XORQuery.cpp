// coding ninjas
// https://www.codingninjas.com/studio/problems/xor-query_893314
#include <bits/stdc++.h> 
vector<int> xorQuery(vector<vector<int>> &queries)
{
	// Write your code here
	vector<int> ans;
	for(auto x: queries)
	{
		if(x[0]==1) ans.push_back(x[1]);
		else{
			for(int i=0;i<ans.size();i++)
			{
				ans[i]=ans[i]^x[1];
			}
		}
	}
	return ans;
}