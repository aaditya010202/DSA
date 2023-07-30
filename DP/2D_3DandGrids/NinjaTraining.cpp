// coding ninjas
//NEW RECURSION
// int solve( vector<vector<int>> &points, int day ,int last)
// {
//     int maxi=0;
//     if(day==0)
//     {
//         int maxi=0;
//         for(int i=0;i<3;i++)
//         {
//             if(i!=last) maxi=max(maxi,points[0][i]);
//         }
//         return maxi;
//     }

//     maxi=0;
//     for(int i=0;i<3;i++)
//     {
//         if(i!=last){
//             int p=points[day][i]+solve(points,day-1,i);
//             maxi=max(maxi,p);
//         }
//     }
//     return maxi;
// }
// int ninjaTraining( int n, vector<vector<int>> &points)
// {
//     return solve(points,n-1,n);
// }


//NEW MEMOIZATION
int solve( vector<vector<int>> &points, int day ,int last,vector<vector<int>> &dp)
{
    int maxi=0;
    if(day==0)
    {
        maxi=0;
        for(int i=0;i<3;i++)
        {
            if(i!=last) maxi=max(maxi,points[0][i]);
        }
        return maxi;
    }

    if(dp[day][last]!=-1) return dp[day][last];

    maxi=0;
    for(int i=0;i<3;i++)
    {
        if(i!=last){
            int p=points[day][i]+solve(points,day-1,i,dp);
            maxi=max(maxi,p);
        }
    }
    return dp[day][last]=maxi;
}

int ninjaTraining( int n, vector<vector<int>> &points)
{
    vector < vector < int > > dp(n, vector < int > (4, -1));
    return solve(points,n-1,3,dp);
}


//NEW TABULATION


// int ninjaTraining( int n, vector<vector<int>> &points)
// {
//     vector < vector < int > > dp(n, vector < int > (4,0));
//     dp[0][0]=max(points[0][1],points[0][2]);
//     dp[0][1]=max(points[0][0],points[0][2]);
//     dp[0][2]=max(points[0][0],points[0][1]);
//     dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));

//     for(int days=1;days<n;days++)
//     {
//         for(int last=0;last<4;last++)
//         {
//             dp[days][last]=0;
//             for(int task=0;task<3;task++)
//             {
//                 if(last!=task){
//                     int p=points[days][task]+dp[days-1][task];
//                     dp[days][last]=max(p,dp[days][last]);
//                 }
//             }
//         }
//     }

//     return dp[n-1][3];
// }