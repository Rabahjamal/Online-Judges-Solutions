#include <bits/stdc++.h>
using namespace std;
map<int, vector<int> >tree;
char grid[1000][1000];
int graph[1000][1000];
bool vis[1000005];
 
int c, r, ans, mx, ret, cnt;
 
bool valid(int i, int j) {
 
    return (i >= 0 && i < r && j >= 0 && j < c);
 
}
 
void dfs(int v) {
 
    for(int i = 0; i < tree[v].size(); i++){
        int node = tree[v][i];
        if(!vis[node]){
            vis[node] = 1;
            cnt++;
            if(cnt > mx){
                ret = node;
                mx = cnt;
                ans = cnt;
            }
            dfs(node);
            cnt--;
        }
    }
}
 
int main()
{
    int t;
    cin >> t;
    while(t--){
        int a = 0;
        cin >> c >> r;
        int x = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> grid[i][j];
                if(grid[i][j] == '#')
                    graph[i][j] = -1;
                else
                    graph[i][j] = a++;
                vis[x++] = 0;
            }
        }
 
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
               if(graph[i][j] != -1){
                    if(valid(i + 1, j) && graph[i + 1][j] != -1)
                        tree[graph[i][j]].push_back(graph[i + 1][j]);
                    if(valid(i - 1, j) && graph[i - 1][j] != -1)
                        tree[graph[i][j]].push_back(graph[i - 1][j]);
                    if(valid(i, j + 1) && graph[i][j + 1] != -1)
                        tree[graph[i][j]].push_back(graph[i][j + 1]);
                    if(valid(i, j - 1) && graph[i][j - 1] != -1)
                        tree[graph[i][j]].push_back(graph[i][j - 1]);
               }
            }
        }
        ret = 0, ans = 0, cnt = 0, mx = 0;
        vis[0] = 1;
        dfs(0);
 
        int y = 0;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                vis[y++] = 0;
        ans = 0, cnt = 0, mx = 0;
        vis[ret] = 1;
        dfs(ret);
 
         cout << "Maximum rope length is " << ans << "." << endl;
         tree.clear();
    }
    return 0;
}
