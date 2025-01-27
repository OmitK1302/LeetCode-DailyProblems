class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Step 1: Initialize a 2D matrix to store reachability
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));
        
        // Step 2: Populate the direct prerequisites
        for (const vector<int>& p : prerequisites) {
            reachable[p[0]][p[1]] = true;
        }
        
        // Step 3: Floyd-Warshall Algorithm to compute transitive closure
        for (int k = 0; k < numCourses; ++k) {      // Intermediate node
            for (int i = 0; i < numCourses; ++i) {  // Starting node
                for (int j = 0; j < numCourses; ++j) { // Ending node
                    if (reachable[i][k] && reachable[k][j]) {
                        reachable[i][j] = true;
                    }
                }
            }
        }
        
        // Step 4: Answer queries
        vector<bool> res;
        for (const vector<int>& query : queries) {
            res.push_back(reachable[query[0]][query[1]]);
        }
        
        return res;
    }
};
