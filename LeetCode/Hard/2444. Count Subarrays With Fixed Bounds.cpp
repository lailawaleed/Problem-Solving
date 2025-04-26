//TimeComplexity  : O(n)
//SpaceComplexity : O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long answer = 0;
        int n = nums.size();
        int minIdx=-1, maxIdx=-1 , badIdx=-1;
        for(int i=0;i<n;i++){
            if(nums[i] < minK || nums[i] > maxK ){
                minIdx=-1;
                maxIdx=-1;
                badIdx=i;
            }
            else
            {
                if (nums[i] == minK) minIdx = i;
                if (nums[i] == maxK) maxIdx = i;
                if (minIdx != -1 && maxIdx != -1) {
                    answer += (long long)(min(minIdx, maxIdx) - badIdx);
                }
            }
        }
        return answer;
    }
};
