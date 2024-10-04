//Link : https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n=skill.size()-1;
        // 0 1 2 3 4 5
        // 1 2 3 3 4 5
        long long pairSum=skill[0]+skill[n];
        long long chemistry=skill[0]*skill[n];
        for(int i=1;i<(n/2)+1;i++){
            if(skill[i]+skill[n-i]==pairSum){
                chemistry+=skill[i]*skill[n-i];
            }
            else
            {
                chemistry=-1;
                break;
            }
        }
        return chemistry;
    }
};



void printVector(const vector<int>& vec) {
    cout << "{ ";
    for (const auto& val : vec) {
        cout << val << " ";
    }
    cout << "}";
}


void testCase1() {
    Solution solution;
    vector<int> skills = {1, 1, 2, 3};
    cout << "Test Case 1: Input: ";
    printVector(skills);
    cout << " | Output: " << solution.dividePlayers(skills)  << endl;
}

void testCase2() {
    Solution solution;
    vector<int> skills = {1, 2, 3, 4, 5, 6};
    cout << "Test Case 2: Input: ";
    printVector(skills);
    cout << " | Output: " << solution.dividePlayers(skills) <<endl;
}


int main() {
    testCase1();
    testCase2();

    return 0;
}
