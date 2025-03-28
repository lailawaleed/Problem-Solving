// Link  :https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/
// TimeComplexity  : O(m*n*log(m*n))
// SpaceComplexity : O(n*m)
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0}; 
    int dy[4] = {0, 1, 0, -1}; 

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int numOfRows = grid.size();       // m
        int numOfColumns = grid[0].size(); // n
        int numOfQueries = queries.size(); // k

        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < numOfQueries; i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> result(numOfQueries);
        vector<vector<bool>> visited(numOfRows, vector<bool>(numOfColumns, false));
        priority_queue<pair<int, pair<int, int>>, 
                      vector<pair<int, pair<int, int>>>,
                      greater<pair<int, pair<int, int>>>> pq;

        int points = 0;
        for (int i = 0; i < numOfQueries; i++) {
            int query = sortedQueries[i].first;
            int idx = sortedQueries[i].second;

          if (grid[0][0] < sortedQueries[i].first && !visited[0][0]) {
                pq.push({grid[0][0], {0, 0}});
                visited[0][0] = true;
            }

            // Process all cells in the heap that are less than current query
            while (!pq.empty() && pq.top().first < query) {
                auto current = pq.top();
                pq.pop();
                points++;

                int x = current.second.first;
                int y = current.second.second;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && nx < numOfRows && ny >= 0 && ny < numOfColumns && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        pq.push({grid[nx][ny], {nx, ny}});
                    }
                }
            }
            result[idx] = points;
        }

        return result;
    }
};
