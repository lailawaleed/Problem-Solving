//Link : https://leetcode.com/problems/find-unique-binary-string/description/
//TimeComplexity : O(2^N)
//SpaceComplexity: O(2^N)
class Solution {
public:
    string generate(string s,unordered_set<string>& numSet){
        if(s.size()==numSet.size()){
            return (numSet.find(s)==numSet.end()?s:"");
        }
        for(char ch:{'1','0'}){
            string result=generate(s+ch,numSet);
            if(!result.empty()){
                return result;
            }
        }
        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>numSet(nums.begin(),nums.end());
        return generate("",numSet);
    }
};
//------------------------------------------------------ 2) Second Solution -----------------------------------------------------------------
//TimeComplexity : O(2^N)
//SpaceComplexity: O(N)
class Solution {
public:
    bool generate(string&s,unordered_set<string>& numSet){
        if(s.size()==numSet.size()){
            return numSet.find(s)==numSet.end();
        }
        for(char ch:{'1','0'}){
            s.push_back(ch);
            if(generate(s,numSet))return true;
            s.pop_back();
        }
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>numSet(nums.begin(),nums.end());
        string result="";
        generate(result,numSet);
        return result;
    }
};
//------------------------------------------------------ 3) Third Solution ----------------------------------------------------------------
//TimeComplexity : O(n)
//SpaceComplexity: O(1)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result;
        for(int i=0;i<nums.size();i++){
            (nums[i][i]=='1')?result.push_back('0'):result.push_back('1');
        }
        return result;
    }
};
