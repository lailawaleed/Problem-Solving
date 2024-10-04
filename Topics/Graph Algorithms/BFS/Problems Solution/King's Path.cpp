#include <iostream>
#include <map>
#include <queue>

using namespace std;

////////// - - - - - - - - -  - - - - - - - - - - -وَاذْكُر رَّبَّكَ إِذَا نَسِيتَ وَقُلْ عَسَىٰ أَن يَهْدِيَنِ رَبِّي لِأَقْرَبَ مِنْ هَٰذَا رَشَدًا - -  - - - - - -  - - - - - - - - - - -//
//
/////*----------------------------------------------------------L-A-I-L-A----------------------------------------------------------*/

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

map<pair<int,int>,bool>allowed;
map<pair<int, int>, int> depth;
void bfs(int x,int y)
{
    depth[{x,y}]=0;
    queue<pair<int,int>> q;
    q.push({x,y});
    while (!q.empty())
    {
        auto [x,y]=q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!depth.count(make_pair(nx,ny))&&allowed[{nx,ny}]){
                depth[{nx, ny}] = depth[{x, y}] + 1;
                q.push({nx,ny});
            }
        }
    }
}

int main() {
    int x0,y0,x1,y1;
    cin >> x0>>y0>>x1>>y1;
    int n;
    cin>>n;
    while (n--)
    {
        int row,y1,y2;
        cin>>row>>y1>>y2;
        for (int i = y1; i <= y2; i++) {
            allowed[{row,i}]=true;
        }
    }

    bfs(x0,y0);
    if(depth.count(make_pair(x1,y1))){
        cout<<depth[{x1,y1}];
    }
    else{
        cout<<-1;
    }


    return 0;
}



