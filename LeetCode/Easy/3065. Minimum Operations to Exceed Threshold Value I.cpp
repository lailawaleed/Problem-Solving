//https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/
//TimeComplexity : O(n)
//SpaceComplexity : O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<k){
                count++;
            }
        }
        return count;
    }
};
