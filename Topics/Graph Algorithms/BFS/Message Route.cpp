//Link:https://cses.fi/problemset/result/10729499/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

////////// - - - - - - - - -  - - - - - - - - - - -وَاذْكُر رَّبَّكَ إِذَا نَسِيتَ وَقُلْ عَسَىٰ أَن يَهْدِيَنِ رَبِّي لِأَقْرَبَ مِنْ هَٰذَا رَشَدًا - -  - - - - - -  - - - - - - - - - - -//
//
/////*----------------------------------------------------------L-A-I-L-A----------------------------------------------------------*/

vector<vector<int>> graph;
vector<int> depth;
vector<int> parent;

void bfs(int source) {
    queue<int> q;
    q.push(source);
    depth[source] = 0;
    parent[source] = -1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();


        for (auto ch : graph[node]) {
            if (depth[ch] == -1) {
                q.push(ch);
                depth[ch] = depth[node] + 1;
                parent[ch] = node;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);


    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    depth.resize(n + 1, -1);
    parent.resize(n + 1, -1);

    bfs(1);


    if (depth[n] == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }


    vector<int> path;
    int temp = n;
    while (temp != -1) {
        path.push_back(temp);
        temp = parent[temp];
    }


    cout << depth[n] + 1 << "\n";
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }

    return 0;
}
