// coding ninjas

int students(vector<int>& arr, int pages)
{
    long long sum=0;
    int st=1;
    for(int i=0;i<arr.size();i++)
    {
        if(sum+arr[i]<=pages)
        {
            sum+=arr[i];
        }
        else{
            sum=arr[i];
            st++;
        }
    }
    return st;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n) return -1;
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high)
    {
        int mid=((low+high)/2);
        if(students(arr,mid)>m) low=mid+1;
        else high=mid-1;

        //Why does this code not work...
        // if(students(arr,mid)<m) high=mid-1;
        // else low=mid+1;
    }
    return low;
}