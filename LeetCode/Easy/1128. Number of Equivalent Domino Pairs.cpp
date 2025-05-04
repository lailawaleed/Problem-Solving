//TimeComplexity:  O(n)
//SpaceComplexity: O(k) k: unique pairs [a, b]
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string, int> seen;
        int count = 0;

        for (const auto& domino : dominoes) {
            int a = min(domino[0], domino[1]);
            int b = max(domino[0], domino[1]);

            string key = to_string(a) + "," + to_string(b);

            if (seen.find(key) != seen.end()) {
                count += seen[key];
            }

            seen[key]++;
        }
        return count;
    }
};
// ========================================================= 2) Second Solution ===========================================================
//TimeComplexity:  O(n)
//SpaceComplexity: O(1)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count = 0;
        int freq[10][10] = {0}; 
        
        for (const auto& domino : dominoes) {
            int a = min(domino[0], domino[1]);
            int b = max(domino[0], domino[1]);
            count += freq[a][b]; 
            freq[a][b]++;
        }
        
        return count;
    }
};
