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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, d, a, b;
    cin >> n >> d >> a >> b;
    vector<pair<ll, int> >V;
    for(int i=0; i<n; i++) {
        ll x, y;
        cin >> x >> y;
        ll c=x*a+y*b;
        V.push_back({c, i+1});
    }
    sort(all(V));
    ll i=0, mem=0, ans=0;
    while(i<n&&mem+V[i].F<=d) {
        ans++;
        mem+=V[i++].F;
    }
    cout << ans << endl;
    for(int i=0; i<ans; i++) {
        cout << V[i].S << " " ;
    }
    return 0;
}
