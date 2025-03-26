//Link : https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/
//Time: O(n m log(n m)) 
//Space: O(n m) 

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        int firstElementRemainder = grid[0][0] % x;
        
        // Flatten the grid into a 1D vector
        vector<int> v;
        for (const auto& row : grid) {
            for (int num : row) {
                if (num % x != firstElementRemainder) {
                    return -1;
                }
                v.push_back(num);
            }
        }
        
        sort(v.begin(), v.end());
        int middle = v[v.size() / 2]; 
        
        int minOperation = 0;
        for (int num : v) {
            minOperation += abs(num - middle) / x;
        }
        
        return minOperation;
    }
};
