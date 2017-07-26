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

int n;
int p[100001];
int cur[100001];
int lvl[100001];
int vis[100001];
int goal[100001];
set<int>ans;
vector< vector<int> >adj(100001);

void dfs(int start, int l){
    vis[start]=1;
    lvl[start]=l;
    for(int i=0; i<adj[start].size(); i++){
        int node=adj[start][i];
        if(!vis[node]){
            p[node]=start;
            dfs(node, l+1);
        }
    }
}

void DFS(int start, int a, int b){
    vis[start]=1;
    for(int i=0; i<adj[start].size(); i++){
        int node=adj[start][i];
        if(!vis[node]){
            int x=lvl[node]%2;
            if((x&1 && b&1)||(x%2==0 && a&1))
                cur[node]=!cur[node];
            if(cur[node]!=goal[node]){
                cur[node]=goal[node];
                ans.insert(node);
                if(x&1)
                    DFS(node, a, b+1);
                else
                    DFS(node, a+1, b);
            }
            else
                DFS(node, a, b);
        }
    }

}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        cin>>cur[i];
    }
    for(int i=1; i<=n; i++){
        cin>>goal[i];
    }
    dfs(1, 0);
    memset(vis, 0, sizeof vis);
    if(cur[1]!=goal[1]){
        cur[1]=goal[1];
        ans.insert(1);
        DFS(1, 1, 0);
    }
    else
        DFS(1, 0, 0);
    cout << ans.size() << endl;
    for(set<int>::iterator it=ans.begin(); it!=ans.end(); it++)
        cout << *it << endl;
    return 0;
}
