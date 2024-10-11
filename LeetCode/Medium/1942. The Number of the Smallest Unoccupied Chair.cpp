//Link : https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/

//Time Complexity:Nlog(N)
//Space Complexity:N
struct Person{
    int num;
    int t1;
    int t2;
};
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<Person> people(times.size());
        for (int i = 0; i < times.size(); i++)
        {
            people[i]={i,times[i][0],times[i][1]};
        }
        
      
        sort(people.begin(),people.end(),[](const Person &a,const Person&b){
            return a.t1<b.t1;
        });
        int currentChair=0;
        
        //leave,chair
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>chairs;
        vector<int>chairNumberOfPerson(people.size());
        set<int>availableChairs;
        for(auto person:people)
        {
            while (!chairs.empty() && chairs.top().first <= person.t1) {
                availableChairs.insert(chairs.top().second);
                chairs.pop();
            }
            if(!availableChairs.empty())
            {
                auto it = availableChairs.begin();
                chairNumberOfPerson[person.num] = *it;
                chairs.emplace(person.t2, *it);
                availableChairs.erase(*it);
            }
            else
            {
                chairNumberOfPerson[person.num] = currentChair;
                chairs.emplace(person.t2, currentChair);
                currentChair++;
            }
        }
        return chairNumberOfPerson[targetFriend];
    }
};
