// Link: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
// Time Complexity: O(n * log(M)) where n is candies.size() and M is total candies / k
// Space Complexity: O(1) as we only use a constant amount of extra space
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();           
        long long left = 0;              // Smallest possible 
        long long right = 0;             // Largest possible 
        
        for (int i = 0; i < n; i++) {
            right += candies[i];
        }
        right = right / k + 1;           
        
        int result = 0;                  // Store the maximum feasible candies
        

        while (left <= right) {
            long long mid = left + (right - left) / 2; 
            
            if (mid == 0) {              // Avoid division by zero
                left = mid + 1;
                continue;
            }

            // Count total piles of size mid
            long long piles = 0;         
            for (int i = 0; i < n; i++) {
                piles += candies[i] / mid; 
            }
            
            if (piles >= k) {            // Can we give k kids this many candies?
                result = mid;            // Save this as a possible answer
                left = mid + 1;          // Try a larger number
            } else {
                right = mid - 1;         // Try a smaller number
            }
        }
        
        return result;                  
    }
};
