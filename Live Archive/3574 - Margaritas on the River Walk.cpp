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

int v, d;
int a[31];
int dp[31][5001][1001];

int solve(int idx, int cost, int mn) {
    if(cost > d)
        return 0;
    if(idx >= v) {
        return (d-cost<mn?1:0);
    }
    int &ret=dp[idx][cost][mn];
    if(ret != -1)
        return ret;
    int x1=solve(idx+1, cost, min(mn, a[idx]));
    int x2=0;
    if(a[idx]<=1000)
        x2=solve(idx+1, cost+a[idx], mn);
    return ret=x1+x2;
}

int main()
{
    int n, tst=1;
    cin >> n;
    while(n--) {
        cin >> v >> d;
        for(int i=0; i<v; i++) {
            cin >> a[i];
        }
        memset(dp, -1, sizeof dp);
        int ans=solve(0, 0, 1000);
        cout << tst++ << " " << ans << "\n";
    }
    return 0;
}
