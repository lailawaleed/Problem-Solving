//Link : https://leetcode.com/problems/maximal-score-after-applying-k-operations/


//Time Complexity :
//Space Complexity : 
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long maxScore=0;
        priority_queue<int>pq;
        for(int num:nums){
            pq.push(num);
        }
        while (k--){
            int t=pq.top();
            maxScore+=t;
            pq.pop();
            pq.push(ceil(t/3.0));
        }
        return maxScore;
    }
};
