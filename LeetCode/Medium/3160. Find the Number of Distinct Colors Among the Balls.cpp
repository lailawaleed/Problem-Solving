// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/?envType=daily-question&envId=2025-02-07
//Time Complexity :  O(N)
//Space Complexity : O(N)
//RunTime : Beats 28.30%
//Memory : Beats 20.90%
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries) {
        vector<int> result;
        unordered_map<int, int> ballColors, colorFrequency;
        for (auto query: queries) {
            int ball = query[0];
            int newColor = query[1];
            int oldColor = ballColors[ball];
            if (oldColor) {
                colorFrequency[oldColor]--;
                if (!colorFrequency[oldColor]) {
                    colorFrequency.erase(oldColor);
                }
            }
            colorFrequency[newColor]++;
            ballColors[ball] = newColor;
            result.push_back(colorFrequency.size());
        }
        return result;
    }
};

// -------------------------------------------------------------------------------------------------------------------------------------
//RunTime :  Beats 85.85%
//Memory : Beats 98.07%
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries) {
        int n = queries.size();
        vector<int> result(n);
        unordered_map<int, int> ballColors, colorFrequency;
        for (int i = 0; i < n; i++) {
            int ball = queries[i][0];
            int newColor = queries[i][1];
            int oldColor = ballColors[ball];
            if (oldColor) {
                colorFrequency[oldColor]--;
                if (!colorFrequency[oldColor]) {
                    colorFrequency.erase(oldColor);
                }
            }
            colorFrequency[newColor]++;
            ballColors[ball] = newColor;
            result[i] = colorFrequency.size();
        }
        return result;
    }
};

auto init = [] {   ///Fast input & output
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

