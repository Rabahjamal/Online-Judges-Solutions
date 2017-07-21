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

    int n, m;
    vector<pair<ll, ll> >V;
    while(cin >> n >> m) {
        if(!n&&!m)
            return 0;
        for(int i=0; i<n; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            V.push_back({c, c+d-1});
        }
        for(int i=0; i<m; i++) {
            int a, b, ans=0;
            cin >> a >> b;
            for(int j=0; j<n; j++) {
                if(V[j].F>=a && V[j].F<=a+b-1)
                    ans++;
                else if(a>=V[j].F && a<=V[j].S)
                    ans++;
            }
            cout << ans << "\n";
        }
        V.clear();
    }
    return 0;
}
