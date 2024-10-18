//Link : https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/

//Time Complexity : 2^N
//Space Complexity : N
class Solution 
{
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR=0;
        for(auto num:nums){
            maxOR|=num;
        }
        int sz=nums.size();
        int ans=0;
        for (int mask = 1; mask<(1LL<<sz); mask++)
        {
            int ORS=0;
            for (int i = 0; i <sz; i++)
            {
                if(mask & (1LL<<i))
                {
                    ORS|=nums[i];
                }
            }
            if(ORS==maxOR){
                ans+=1;
            }
            cout<<endl;
        }
        return ans;
    }
};
