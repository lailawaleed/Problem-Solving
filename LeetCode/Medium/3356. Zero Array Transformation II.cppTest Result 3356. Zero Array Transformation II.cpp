// Link: https://leetcode.com/problems/zero-array-transformation-ii/
// TimeComplexity: O((n + q) * log q)
// SpaceComplexity: O(n)

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        // Binary search for the minimum k
        int left = 0, right = m;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isZeroArray(nums, queries, mid)) {
                result = mid;
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }
        return result;
    }
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries,int k) {
        int n = nums.size();
        vector<long long> count(n + 1); 
        
        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val=queries[i][2];
            count[l+1] += val;            
            if (r + 2 <= n) {
                count[r + 2] -= val;    
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
//------------------------------------------------------- 2) Second Solution --------------------------------------------------------------

// TimeComplexity: O(n + q)
// SpaceComplexity: O(n)

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        int idx = 0;
        vector<long long> count(n); 
        
        long long total_decrement = 0;  // Running sum
        
        for (int i = 0; i < n; i++) {
            total_decrement += count[i];  
            
            while (total_decrement < nums[i]) {
                if (idx >= q) {
                    return -1;
                }
                int l = queries[idx][0];
                int r = queries[idx][1];
                int val = queries[idx][2];
                idx++;
                
                if (r >= i) {
                    count[max(i, l)] += val;
                    if (r + 1 < n) {
                        count[r + 1] -= val;
                    }
                    if (max(i, l) == i) {  // Only update if affects i
                        total_decrement += val;
                    }
                }
            }
        }
        return idx;
    }
};
