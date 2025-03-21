class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int numOfRecipes=recipes.size();
        unordered_map<string, vector<string>> adjList; // ingredient -> recipes that depend on it
        unordered_map<string,int>inDegree;             // recipe -> number of ingredients needed
        for(int i=0;i<numOfRecipes;i++){
            for(string ingredient:ingredients[i]){
                adjList[ingredient].push_back(recipes[i]);
            }
        }
        for(int i=0;i<numOfRecipes;i++){
            inDegree[recipes[i]]=ingredients[i].size();            
        }

        //BFS
        queue<string>q;
        for(string supply:supplies){
            q.push(supply);
        }
        vector<string>result;
        while(q.size()){
            auto current=q.front();
            q.pop();
            if(inDegree.find(current)!=inDegree.end()){
                result.push_back(current);
            }
            for(string recipe:adjList[current]){
                inDegree[recipe]--;
                if(inDegree[recipe]==0){
                    q.push(recipe);
                }
            }
        }
        return result;
    }
};
