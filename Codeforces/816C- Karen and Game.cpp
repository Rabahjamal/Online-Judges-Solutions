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

int res[101][101], fin[101][101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> fin[i][j];
        }
    }
    int ans=0;
    vector<pair<string, pair<int, int> > >vp;
    if(n<=m) {
        int mn;
        for(int i=0; i<n; i++) {
            mn=inf;
            for(int j=0; j<m; j++) {
                mn=min(mn, fin[i][j]);
            }
            for(int j=0; j<m; j++) {
                res[i][j] = mn;
            }
            if(mn)
                vp.push_back({"row", {i+1, mn}}), ans+=mn;
        }
        for(int i=0; i<m; i++) {
            int mn1=inf, mn2=inf;
            for(int j=0; j<n; j++) {
                mn1=min(mn1, fin[j][i]);
                mn2=min(mn2, res[j][i]);
            }
            for(int j=0; j<n; j++) {
                res[j][i]+=(mn1-mn2);
            }
            if(mn1-mn2)
                vp.push_back({"col",{i+1, mn1-mn2}}), ans+=(mn1-mn2);
        }
    }
    else {
        for(int i=0; i<m; i++) {
            int mn1=inf;
            for(int j=0; j<n; j++) {
                mn1=min(mn1, fin[j][i]);
            }
            for(int j=0; j<n; j++) {
                res[j][i]=mn1;
            }
            if(mn1)
                vp.push_back({"col",{i+1, mn1}}), ans+=mn1;
        }
        int mn;
        for(int i=0; i<n; i++) {
            int mn1=inf, mn2=inf;
            for(int j=0; j<m; j++) {
                mn1=min(mn1, fin[i][j]);
                mn2=min(mn2, res[i][j]);
            }
            for(int j=0; j<m; j++) {
                res[i][j]+=(mn1-mn2);
            }
            if(mn1-mn2)
                vp.push_back({"row", {i+1, mn1-mn2}}), ans+=(mn1-mn2);
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(fin[i][j] != res[i][j]) {
                puts("-1");
                return 0;
            }
        }
    }
    cout << ans << "\n";
    for(int i=0; i<vp.size(); i++) {
        while(vp[i].S.S--) {
            cout << vp[i].F << " " << vp[i].S.F << "\n";
        }
    }
    return 0;
}
