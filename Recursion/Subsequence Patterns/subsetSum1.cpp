// coding ninjas
void solve(vector<int> &num, vector<int> &ans,vector<int> &s, int index)
{
	int sum=accumulate(s.begin(),s.end(),0);
	if(index>=num.size())
	{
		ans.push_back(sum);
		return;
	}

	s.push_back(num[index]);
	solve(num,ans,s,index+1);
	s.pop_back();
	solve(num,ans,s,index+1);
}

vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	vector<int> ans;
	vector<int>s;
	solve(num,ans,s,0);
	sort(ans.begin(),ans.end());
	return ans;	
}