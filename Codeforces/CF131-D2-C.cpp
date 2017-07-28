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

ull dp[31][31];

ull solve(ull n, ull r) {
    if(n == r)
        return 1;
    if(r==1)
        return n;
    ull &ret=dp[n][r];
    if(ret != -1)
        return ret;
    return ret=solve(n-1, r)+solve(n-1, r-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ull n, m, t, ans=0;
    cin >> n >> m >> t;
    vector<pair<ull, ull> >V;
    ull b, g;
    if(n>=t) {
        b=t-1, g=1;
    }
    else {
       b=n, g=t-n;
    }
    while(b>=4) {
        if(b+g<=t&&b<=n&&g<=m)
            V.push_back({b, g});
        b--, g++;
    }
    for(int i=0; i<V.size(); i++) {
        memset(dp, -1, sizeof dp);
        ull a = solve(n, V[i].F);
        memset(dp, -1, sizeof dp);
        ull b = solve(m, V[i].S);
        ans+=(a*b);
    }
    cout << ans << endl;
    return 0;
}
