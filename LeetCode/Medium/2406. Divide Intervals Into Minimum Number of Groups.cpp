//Link : https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        set<pair<int,int>>st;
        for(int i=0;i<intervals.size();i++){
            st.insert({intervals[i][0],intervals[i][1]});
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans=1;

        if(st.size()<intervals.size()){
            ans+=intervals.size()-st.size();
        }

        //[[1,5], [1,10], [2,3], [5,10], [6,8]]
        for(auto p:st)
        {
            int start=p.first;
            int end=p.second;
            if(!pq.empty()){
                int top=pq.top();
                if(top<start){
                    pq.pop();
                }
                else{
                    ans++;
                }
                pq.push(end);
            }
            else
            {
                pq.push(end);
            }
        }
        return ans;
    }
};
