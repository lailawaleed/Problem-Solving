// Link: https://leetcode.com/problems/zero-array-transformation-i/
// TimeComplexity: O(n + q)
// SpaceComplexity: O(n)
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> count(n + 1); 
        
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            count[l+1] += 1;            
            if (r + 2 <= n) {
                count[r + 2] -= 1;    
            }
        }
        
   
        for (int i = 1; i <= n; i++) {  
            count[i] += count[i - 1];
             if (nums[i-1] > count[i]) {
                return false;
            }
        }
        return true;
    }
};
