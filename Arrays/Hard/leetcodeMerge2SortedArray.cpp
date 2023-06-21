class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // SOLUTION 1
        // for(int i=0;i<n;i++){
        //     nums1.pop_back();

        // }
        // for(int i:nums2){
        //     nums1.push_back(i);
        // }
        // sort(nums1.begin(),nums1.end());

        // SOLUTION 2
        int j=m;
        for(int i=0;i<n;i++)
        {
            nums1[j]=(nums2[i]);
            j++;
        }
        sort(nums1.begin(),nums1.end());
    }
};