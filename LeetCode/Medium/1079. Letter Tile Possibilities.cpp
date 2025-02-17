//Link : https://leetcode.com/problems/letter-tile-possibilities/
//TimeComplexity : O(N!)
//SpaceComplexity: O(N)
class Solution {
public:
    void solve(string tiles,vector<bool>&used,unordered_set<string>&sequences,string current) {
        if (!current.empty())
            sequences.insert(current);
        for (int i = 0; i < tiles.size(); i++) {
            if (used[i])
                continue;
            used[i] = true;
            solve(tiles, used, sequences, current + tiles[i]);
            used[i] = false;
        }

    }
    int numTilePossibilities(string tiles) {
        vector<bool> used(tiles.size(), false);
        unordered_set<string> sequences;
        solve(tiles, used, sequences, "");
        return sequences.size();
    }
};
