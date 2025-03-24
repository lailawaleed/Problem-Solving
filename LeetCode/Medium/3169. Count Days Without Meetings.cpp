//Link : https://leetcode.com/problems/count-days-without-meetings/
//Time Complexity : O(NlogN)  --> # of Meetings
//Space Complexity : O(N)
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int freeDays = 0;
        
        int firstMeetingStart = meetings[0][0];
        freeDays += firstMeetingStart - 1;

        int lastEndTime = meetings[0][1]; 
        
        for (int i = 1; i < meetings.size(); i++) 
        {
            int currentStart = meetings[i][0];
            int currentEnd = meetings[i][1];
            
            if (currentStart <= lastEndTime) 
            {
                lastEndTime = max(lastEndTime, currentEnd);
            }
            else 
            {
                freeDays += currentStart - lastEndTime - 1;
                lastEndTime = currentEnd;
            }
        }       
        freeDays += days - lastEndTime;
        
        return freeDays;
    }
};
