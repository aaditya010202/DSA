// leetcode
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // int rows=matrix.size();
        // int col=matrix[0].size();

        // for(int i=0;i<rows;i++)
        // {
        //     int low=0;
        //     int high=col-1;
        //     while(low<=high)
        //     {
        //         int mid=((low+high)/2);
        //         if(matrix[i][mid]==target) return true;
        //         else if(matrix[i][mid]<target) low=mid+1;
        //         else high=mid-1;
        //     }
        // }
        // return false;

        
        //OPTIMAL SOLUTION
        int row=0;
        int col=matrix[0].size()-1;
        //place the pointer at the first row and the last column of the matrix.

        while(row<matrix.size() && col>=0 && col<matrix[0].size())
        {
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) row++;
            else col--;
        }
        return false;       
    }
};