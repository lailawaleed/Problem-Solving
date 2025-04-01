//Link : https://leetcode.com/problems/solving-questions-with-brainpower/
//TimeComplexity : O(n)
//SpaceComplexity: O(n)
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1);  
        
        for (int i = n - 1; i >= 0; i--) {
            long long points = questions[i][0];  
            int skip = questions[i][1];          
            
            // Option 1: Skip current question
            long long skipPoints = dp[i + 1];
            
            // Option 2: Solve current question
            long long solvePoints = points;

            int nextIdx = i + skip + 1;  // Next solvable question
            if (nextIdx <= n) {
                solvePoints += dp[nextIdx];
            }
            
            // Take maximum of solving or skipping
            dp[i] = max(skipPoints, solvePoints);
        }
        
        return dp[0];  
    }
};
