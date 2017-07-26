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

int f[1000005];
int h[1000005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    set<int>ss;
    for(int i = 0; i < m; i++){
        cin >> h[i];
        ss.insert(h[i]);
    }
    int ans = 1;
    if(ss.find(ans) != ss.end())
        f[ans]=1;
    for(int i = 0; i < k; i++){
        int u, v;
        cin >> u >> v;
        if(ans == u && !f[u]){
            ans=v;
            if(ss.find(v) != ss.end())
                f[v] = 1;
        }
        else if(ans == v && !f[v]){
            ans=u;
            if(ss.find(u) != ss.end())
                f[u] = 1;
        }
    }
    cout << ans << endl;

    return 0;
}
