// leetcode
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()==goal.length())
        {
            if((s+s).find(goal)!=std::string::npos)return true;
            //npos denotes any index which cannot be accessed, this means the find function could not find the index if it gets equal to npos.
        }
        return false;
    }
};