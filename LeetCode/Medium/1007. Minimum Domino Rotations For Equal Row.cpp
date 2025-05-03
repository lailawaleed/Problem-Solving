//TimeComplexity  : O(n)
//SpaceComplexity : O(1)
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int minRotations = INT_MAX;
        
        // Try each possible value (1 to 6)
        for (int target = 1; target <= 6; target++) 
        {
            int topRotations = 0, bottomRotations = 0;
            bool possible = true;
            
            // Check each domino
            for (int i = 0; i < n; i++) 
            {
                // If neither top nor bottom has the target, it's impossible
                if (tops[i] != target && bottoms[i] != target) {
                    possible = false;
                    break;
                }
                // If top doesn't have target, rotate to make top = target
                if (tops[i] != target) {
                    topRotations++;
                }
                // If bottom doesn't have target, rotate to make bottom = target
                if (bottoms[i] != target) {
                    bottomRotations++;
                }
            }
            
            if (possible) {
                minRotations = min(minRotations, min(topRotations, bottomRotations));
            }
        }
        
        return minRotations == INT_MAX ? -1 : minRotations;
    }
};
