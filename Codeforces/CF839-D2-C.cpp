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

bool vis[100005];
ll dist[100005];
float prop[100005];
set<int>nlf;
vector< vector<int> >tree(100005);

void bfs(int val) {
    queue<int>q;
    q.push(val);
    vis[val] = 1;
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        for(int i = 0; i < tree[top].size(); i++) {
            if(!vis[tree[top][i]] && dist[tree[top][i]] > dist[top]+1) {
                dist[tree[top][i]] = dist[top]+1;
                vis[tree[top][i]] = 1;
                q.push(tree[top][i]);
                nlf.insert(top);
                if(top!=1)
                    prop[tree[top][i]] = prop[top] / (tree[top].size()-1);
                else
                    prop[tree[top][i]] = prop[top] / tree[top].size();
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        dist[i+1]=inf;
    }
    dist[n]=inf;
    dist[1]=0;
    prop[1] = 1.0;
    bfs(1);

    float ans = 0, total=0, cnt=0;
    for(int i=1; i<=n; i++) {
        if(!nlf.count(i))
            total+=float(dist[i]) * prop[i];
    }
    ans = total;
    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}
