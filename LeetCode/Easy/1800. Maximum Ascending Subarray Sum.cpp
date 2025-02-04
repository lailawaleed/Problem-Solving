//Link : https://leetcode.com/problems/maximum-ascending-subarray-sum/
//TimeComplexity : O(n)
//SpaceComplexity: O(1)
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int maxSum=0;
        int curr=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                curr+=nums[i];
            }
            else
            {
                maxSum=max(maxSum,curr);
                curr=nums[i];
            }
        }
        maxSum=max(maxSum,curr);
        return maxSum;
    }
};
