// leetcode
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> arr(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        for (auto x : prerequisites) {
            arr[x[1]].push_back(x[0]);
            inDegree[x[0]]++; // Count incoming edges
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for (int x : arr[front]) {
                inDegree[x]--;
                if (inDegree[x] == 0) {
                    q.push(x);
                }
            }
        }

        if (ans.size() != numCourses) {
            return {}; // Return empty array if not all courses can be taken
        }
        return ans;
    }
};
