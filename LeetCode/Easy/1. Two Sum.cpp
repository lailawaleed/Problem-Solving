//Link : https://leetcode.com/problems/two-sum/
//TimeComplexity:  O(n)
//SpaceComplexity: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>result(2);
        for(int i=0;i<nums.size();i++){
            int complement=target-nums[i];
            if(mp.find(complement)!=mp.end()){
                result[0]=mp[complement];
                result[1]=i;
                return result;
            }
            mp[nums[i]]=i;
        }
        return result;
    }
};
