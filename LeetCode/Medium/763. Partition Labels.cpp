//Link : https://leetcode.com/problems/partition-labels/
//TimeComplexity : O(n)
//SpaceComplexity  O(1)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastOccurrence(26);
        
        for (int i = 0; i < s.size(); ++i) {
            lastOccurrence[s[i] - 'a'] = i;
        }
        
        vector<int> answer;
        int start = 0;
        int end = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            end = max(end, lastOccurrence[s[i] - 'a']);
            
            if (i == end) {
                answer.push_back(end - start + 1);
                start = end + 1;
            }
        }
        
        return answer;
    }
};
