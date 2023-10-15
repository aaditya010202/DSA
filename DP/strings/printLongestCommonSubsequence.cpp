// coding ninjas
string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.	
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];

			else
			{
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	int len=dp[n][m];
	// string ans(len, '$');
	// OR
	string ans;
	
	for(int i=0;i<len;i++) ans+='$';

	int i=n, j=m;
	while(i>0 && j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			ans[len-1]=s1[i-1];
			len--;
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1])
		{
			i--;

		}
		else
		{
			j--;
		}
	}
	return ans;

}