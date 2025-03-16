//Link : https://leetcode.com/problems/minimum-time-to-repair-cars/
//TimeComplexity : O(m * log(r * c²)) --> where m is ranks.size(),r is minRank and c is cars
//SpaceComplexity: O(1)
class Solution {
public:
    bool canRepair(vector<int>& ranks, int cars, long long time) {
        long long check = 0;
        // r*n² = time
        for(int i = 0; i < ranks.size(); i++) {
            check += 1LL * sqrt(time / ranks[i]);
        }
        return check >= cars;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        long long minRank = *min_element(ranks.begin(), ranks.end());
        long long left = 1;
        long long right = minRank * 1LL * cars * cars;
        while(left <= right) {
            long long mid = left + (right - left) / 2;
            if(canRepair(ranks, cars, mid)) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
