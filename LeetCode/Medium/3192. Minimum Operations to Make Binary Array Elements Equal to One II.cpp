//Link : https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/
// TimeComplexity : O(n)
// SpaceComplexity: O(1)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int arraySize = nums.size(); 
        int minOperation = 0;       
        for (int i = 0; i < arraySize; i++) {
            /* Determine if an operation is needed at index i
                -  minOperation % 2: Checks if the number of flips so far is odd (1) or even (0)
                   - Even (0): No inversion, flip if nums[i] is 0 (!nums[i])
                   - Odd (1): Suffix inverted, flip if nums[i] is 1 (nums[i])
                   The expression evaluates to 1 (true) if a flip is required, 0 (false) otherwise
                   += adds 1 to minOperation when the condition is true
            */   
            minOperation+=(minOperation%2 && nums[i]) || (!(minOperation%2) && !nums[i]);
        }
        return minOperation;
    }
};
