// Link: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/
// TimeComplexity: O(N) - Single pass up to n-2
// SpaceComplexity: O(1) - In-place modification
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int arraySize = nums.size(); 
        int minOperation = 0;       // Operation counter
        
        // Loop until last triplet position
        for (int i = 0; i < arraySize - 2; i++) {
            if (!nums[i]) {         // If current element is 0
                nums[i] = 1;        // Set to 1
                nums[i + 1] = 1 - nums[i + 1]; // Flip next (0->1, 1->0)
                nums[i + 2] = 1 - nums[i + 2]; // Flip third
                minOperation++;     // Increment operation count
            }
        }
        
        return (nums[arraySize - 2] == 1 && nums[arraySize - 1] == 1) ? minOperation : -1;
    }
};
