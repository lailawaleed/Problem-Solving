// Link: https://leetcode.com/problems/koko-eating-bananas/
// Time Complexity: O(n * log M) where n is piles.size(), M is max pile size
// Space Complexity: O(1)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();           
        long long left = 1;              
        long long right = 0;             
        
        for (int i = 0; i < n; i++) {
            right = max(right, (long long)piles[i]);
        }      

        int result = 0;                  

        while (left <= right) {
            long long mid = left + (right - left) / 2; 
            
            long long hours = 0;         
            for (int i = 0; i < n; i++) {
                hours += (piles[i] + mid - 1) / mid;
            }
            
            if (hours<=h) {                    
                right = mid - 1;       
                result=mid;  
            } 
            else
            {
                left = mid + 1;         
            }
        }
        
        return result;     
    }
};
