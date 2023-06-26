// leetcode
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=((low+high)/2);
            if(nums[mid]==target) return true;
            if((nums[low]==nums[mid]) && (nums[high]==nums[mid]))
            {
                low++;
                high--;
            }
            else if(nums[low]<=nums[mid])
            {
                if(nums[low]<=target && target<=nums[mid])
                {
                    high=mid-1;
                }else{
                    low=mid+1;
                }
                
            }
            else
            {
                if(nums[mid]<=target && target<=nums[high])
                {
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};

int getInactiveDuration(int d, vector<int> attack) {
    if (attack.empty()) return 0;
    
    sort(attack.begin(), attack.end());
    
    stack<pair<int, int>> s;
    
    s.push({attack[0], attack[0] + d - 1});
    
    for (int i = 1; i < attack.size(); i++) {
        int start = attack[i];
        int end = attack[i] + d - 1;
        
        pair<int, int> top = s.top();
        
        if (start > top.second) {
            s.push({start, end});
        }
        else {
            top.second = max(end, top.second);
            s.pop();
            s.push(top);
        }
    }
    
    int total = 0;
    
    while (!s.empty()) {
        pair<int, int> p = s.top();
        s.pop();
        total += (p.second - p.first + 1);
    }
    return total;
}


#include <vector>

int getInactiveDuration(int d, std::vector<int> attack) {
    int inactiveDuration = 0;
    int previousAttackTime = -1;

    for (int i = 0; i < attack.size(); i++) {
        int currentAttackTime = attack[i];

        if (previousAttackTime >= currentAttackTime) {
            // If the current attack time is less than or equal to the previous attack time,
            // it means the monster is already inactive due to a previous attack.
            inactiveDuration += d;
        } else {
            // If the current attack time is greater than the previous attack time,
            // calculate the inactive duration based on the difference between the current
            // attack time and the previous attack time.
            inactiveDuration += d - (currentAttackTime - previousAttackTime - 1);
        }

        previousAttackTime = currentAttackTime;
    }

    return inactiveDuration;
}
