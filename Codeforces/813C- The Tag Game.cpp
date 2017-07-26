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

bool vis[200001], ok[200001];
int dist[200001], dist2[200001];
vector< vector<int> >tree(200001);

void dfs(int start) {
    vis[start] = 1;
    for(int i=0; i<tree[start].size(); i++) {
        int node=tree[start][i];
        if(!vis[node] && dist[node]>dist2[node] && node!=1) {
            ok[node]=1;
            dfs(node);
        }
    }
}

void bfs(int start, int v) {
    queue<int>q;
    q.push(start);
    while(!q.empty()) {
        int top=q.front();
        if(vis[top])
            continue;
        vis[top]=1;
        q.pop();
        for(int i=0; i<tree[top].size(); i++) {
            int node=tree[top][i];
            if(!vis[node] && node != 1) {
                q.push(node);
                if(v==1)
                    dist[node] = min(dist[node], dist[top]+1);
                else
                    dist2[node] = min(dist2[node], dist2[top]+1);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    for(int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for(int i=1; i<=n; i++) {
        dist[i]=inf;
    }
    dist[1]=0;
    memset(vis, 0, sizeof vis);
    bfs(1, 1);
    for(int i=1; i<=n; i++) {
        dist2[i]=inf;
    }
    dist2[x]=0;
    memset(vis, 0, sizeof vis);
    bfs(x, 2);
    memset(vis, 0, sizeof vis);
    ok[x]=1;
    dfs(x);
    int node=0, d=0;
    for(int i=0; i<= n; i++) {
        if(ok[i] && dist[i]>=d){
            d=dist[i];
            node=i;
        }
    }
    cout << d*2 << endl;
    return 0;
}
