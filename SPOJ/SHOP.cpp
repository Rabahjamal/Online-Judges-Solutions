#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
 
#define F first
#define S second
#define inf INT_MAX
#define INF LONG_LONG_MAX
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
 
char grid[26][26];
int n, m;
vector <vector<pair<int, int> > >adj(1000);
vector<int>dist(1000), mark(1000);
vector<int> parent(1000);
void dijkstra(int start) {
    dist[start] = 0;
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push(make_pair(dist[start], start));
    while(!pq.empty()) {
        int top = pq.top().second;
        pq.pop();
 
        if(mark[top])continue;
        mark[top] = 1;
        for(int i = 0; i < adj[top].size(); i++) {
            if(dist[adj[top][i].first] > dist[top] + adj[top][i].second) {
                dist[adj[top][i].first] = dist[top] + adj[top][i].second;
                pq.push(make_pair(dist[adj[top][i].first], adj[top][i].first));
                parent[adj[top][i].first] = top;
            }
        }
    }
}
 
 
bool check(int i, int j) {
    return (i>=0 && i<m && j>=0 && j<n && grid[i][j] != 'X' && grid[i][j] != 'S');
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n >> m) {
        if(!n && !m)
            break;
        int tmp[30][30];
        int x, y, a, b, cnt = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> grid[i][j];
                if(grid[i][j] == 'S')x = i,  y = j;
                if(grid[i][j] == 'D')grid[i][j] = '0', a = i, b = j;
                tmp[i][j] = cnt++;
                dist[tmp[i][j]] = inf;
                mark[tmp[i][j]] = 0;
            }
        }
 
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 'X' && grid[i][j] != 'D') {
                    if(check(i+1, j))
                        adj[tmp[i][j]].push_back({tmp[i+1][j], grid[i+1][j]-'0'});
                    if(check(i-1, j) )
                        adj[tmp[i][j]].push_back({tmp[i-1][j], grid[i-1][j]-'0'});
                    if(check(i, j+1))
                        adj[tmp[i][j]].push_back({tmp[i][j+1], grid[i][j+1]-'0'});
                    if(check(i, j-1))
                        adj[tmp[i][j]].push_back({tmp[i][j-1], grid[i][j-1]-'0'});
                }
            }
        }
        dijkstra(tmp[x][y]);
        cout << dist[tmp[a][b]] << "\n";
        adj.resize(1000);
        for(int i = 0; i < 1000; i++) {
            adj[i].clear();
        }
        parent.resize(1000);
        mark.resize(1000);
    }
    return 0;
}
