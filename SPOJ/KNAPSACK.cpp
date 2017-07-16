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
 
ll n, m;
ll arr[2001][2];
ll dp[2001][2001];
 
ll solve(int idx, ll rem) {
    if(idx == n || rem == 0)
        return 0;
    ll &ret = dp[idx][rem];
    if(ret != -1)
        return ret;
    ret = 0;
    ll x1 = solve(idx+1, rem);
    ll x2 = 0;
    if(rem-arr[idx][0] >= 0) {
        x2 = solve(idx+1, rem-arr[idx][0])+arr[idx][1];
    }
    return ret = max(x1, x2);
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
        for(int i = 0; i < n; i++) {
            cin >> arr[i][0] >> arr[i][1];
        }
        memset(dp, -1, sizeof dp);
        cout << solve(0, m) << "\n";
 
    return 0;
} 
