//Link : https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

//Time Complexity  : O(N∗K)
//Space Complexity : O(N)
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums)
    {
        vector<int> idx(nums.size(), 0);
        int mini = 1e5+5;
        int maxi = -1e5 - 5;
        int minIdx = 0;
        vector<int> ans(2);
        ans[0] = -1e5;
        ans[1] = 1e5;

        while (true)
        {
            mini = 1e5 + 5;
            maxi = -1e5 - 5;
            minIdx = 0;

            // Find the current minimum and maximum across all lists.
            for (int i = 0; i < nums.size(); i++)
            {

                if (idx[i] >= nums[i].size())
                {
                    return ans;
                }

                int x = nums[i][idx[i]];
                if (x > maxi)
                {
                    maxi = x;
                }
                if (x < mini)
                {
                    mini = x;
                    minIdx = i;
                }
            }

            // Update the result if the current range is smaller.
            if (maxi - mini < ans[1] - ans[0]) {
                ans[0] = mini;
                ans[1] = maxi;
            }

            idx[minIdx]++;
        }
    }
};
