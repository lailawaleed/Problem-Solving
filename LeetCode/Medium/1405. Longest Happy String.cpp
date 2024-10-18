//Link : https://leetcode.com/problems/longest-happy-string/

//Time Complexity  :  O(N)
//Space Complexity :  O(1)
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a > 0) pq.emplace(a, 'a');
        if(b > 0) pq.emplace(b, 'b');
        if(c > 0) pq.emplace(c, 'c');
        
        string result = "";
        
        while(!pq.empty()){
            auto [count1, char1] = pq.top(); pq.pop();
            int n = result.size();
            if(n >=2 && result[n-1] == char1 && result[n-2] == char1){
                if(pq.empty()){
                    break;
                }
                auto [count2, char2] = pq.top(); pq.pop();
                result += char2;
                count2--;
                if(count2 > 0){
                    pq.emplace(count2, char2);
                }
                pq.emplace(count1, char1);
            }
            else{
                result += char1;
                count1--;
                if(count1 > 0){
                    pq.emplace(count1, char1);
                }
            }
        }
        
        return result;
    }
};
