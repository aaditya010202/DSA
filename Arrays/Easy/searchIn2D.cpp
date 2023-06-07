// leetcode solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // for(int i=matrix[0].size()-1,j=0;i<matrix.size()*matrix[0].size(),j<matrix.size();i+=matrix[0].size(),j++){
        //     if(target>matrix[j][i])continue;
        //     else{
        //         for(int m=i-matrix[0].size()+11;m<=i;m++){
        //             if(target==matrix[j][m]) return true;                    
        //         }
        //     }           
        // }
        // return false;
        
        // striver's code
        if(!matrix.size()) return false;
        int n=matrix.size();
        int m=matrix[0].size();

        int low=0;
        int high=(n*m)-1;

        while(low<=high)
        {
            int mid=(low+high)>>1;
            int r=mid/m;
            int c=mid%m;

            if(matrix[r][c]==target) return true;
            else if(matrix[r][c]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
};