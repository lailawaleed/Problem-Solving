//Link : https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/
//Time Complexity : O(NlogN)
//Space Complexity : O(N)
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>>minPQ;
        for (int number: nums) {
            minPQ.push(number*1LL);
        }
        int count=0;
        while (minPQ.size() > 1 && minPQ.top() < k){
            int smallest1=minPQ.top();
            minPQ.pop();
            int smallest2=minPQ.top();
            minPQ.pop();
            minPQ.push(smallest1*2LL+smallest2);
            count++;
        }
        return count;
    }
};
//--------------------------------------------------------- 2) Optimization --------------------------------------------------------------
class Solution {
public:
    int minOperations(vector<int>& nums, int k)
    {
      priority_queue<long long, vector<long long>, greater<long long>>minPQ(nums.begin(),nums.end());
        int count=0;
        while (minPQ.size() > 1 && minPQ.top() < k){
            int smallest1=minPQ.top();
            minPQ.pop();
            int smallest2=minPQ.top();
            minPQ.pop();
            (smallest1*2LL+smallest2)>k? minPQ.push(k+1):minPQ.push(smallest1*2+smallest2);
            count++;
        }
        return count;
    }
};
//--------------------------------------------------------- 3) Using MultiSet -----------------------------------------------------------------
class Solution {
public:
    int minOperations(vector<int>& nums, int k)
    {
        multiset<int>minSet(nums.begin(),nums.end());
        int count=0;
        while (minSet.size() > 1 && *minSet.begin()< k){
            int smallest1=*minSet.begin(); minSet.erase(minSet.begin());
            int smallest2=*minSet.begin(); minSet.erase(minSet.begin());
            (smallest1*2LL+smallest2)>k? minSet.insert(k+1):minSet.insert(smallest1*2+smallest2);
            count++;
        }
        return count;
    }
};
