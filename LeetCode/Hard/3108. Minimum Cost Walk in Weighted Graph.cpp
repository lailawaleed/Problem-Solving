class Solution {
public:
    vector<int>parent,cost;
    int findParent(int u)
    {
        if(parent[u]==u)return u;
        return parent[u]=findParent(parent[u]);
    }
    void join(int u,int v,int weight){
        int parentU=findParent(u);
        int parentV=findParent(v);
        cost[parentU]=cost[parentV]=weight&cost[parentV]&cost[parentU];
        parent[parentV]=parentU;
    }
    int calculateMincost(int u,int v){
        if(findParent(u)==findParent(v)){
            return cost[findParent(u)];
        }
        return -1;
    } 
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        cost=parent=vector<int>(n,-1);
        iota(parent.begin(),parent.end(),0);  //initialize parent[i]=i
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            join(u,v,w);
        }
        vector<int>answer;
        for(auto pair:query){
            int node1=pair[0];
            int node2=pair[1];
            answer.push_back(calculateMincost(node1,node2));
        }
       return answer;
    }
};
