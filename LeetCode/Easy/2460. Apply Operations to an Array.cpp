/**
  Link: https://leetcode.com/problems/apply-operations-to-an-array/
  TimeComplexity:  O(N)
  SpaceComplexity: O(N)
*/
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int>answer(nums.size());
        //1)Apply the Operations
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        //2)Shift 0's
        int index=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
              answer[index++]=nums[i];
            }
        }
        return answer;
    }
};
