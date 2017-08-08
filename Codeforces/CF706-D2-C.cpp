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

vector<string>v;
ll dp[100001][2];
ll arr[100001];

ll solve(int idx, int r, string pstr) {
    if(idx==v.size()) {
        return 0;
    }
    ll &ret=dp[idx][r];
    if(ret!=-1)
        return ret;
    string tmp=v[idx];
    reverse(all(tmp));
    ll x1=1e17, x2=1e17;
    if(v[idx]>=pstr)
        x1=solve(idx+1, 0, v[idx]);
    if(tmp>=pstr)
        x2=solve(idx+1, 1, tmp)+arr[idx];
    return ret=min(x1, x2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }
    memset(dp, -1, sizeof dp);
    ll ans=solve(0, 0, "");
    if(ans==1e17)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}
