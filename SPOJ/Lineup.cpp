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
 
int score[11][11];
ll dp[11][2048];
 
ll solve(int i, int mask) {
    if(i>=11)
        return 0;
    ll &ret=dp[i][mask];
    if(ret!=-1)
        return ret;
    ret=-inf;
    for(int x=0; x<11; x++) {
        if((mask&(1<<x)) && score[x][i]) {
            ret=max(ret, solve(i+1, mask^(1<<x))+score[x][i]);
        }
    }
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    while(n--) {
        for(int i=0; i<11; i++) {
            for(int j=0; j<11; j++) {
                cin >> score[i][j];
            }
        }
        memset(dp, -1, sizeof dp);
        cout << solve(0, 2047) << endl;
    }
    return 0;
}
