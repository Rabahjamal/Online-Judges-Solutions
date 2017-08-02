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

int cnt[11][101][101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q, c;
    cin >> n >> q >> c;
    for(int i = 0; i < n; i++) {
        int x, y, s;
        cin >> x >> y >> s;
        cnt[s][x][y]++;
    }
    for(int i=0; i <= 10; i++) {
        for(int j = 1; j <= 100; j++) {
            for(int k = 1; k <= 100; k++) {
                cnt[i][j][k]+=cnt[i][j-1][k]+cnt[i][j][k-1]-cnt[i][j-1][k-1];
            }
        }
    }
    for(int i=0; i<q; i++) {
        int t, x1, y1, x2, y2, ans=0;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        for(int p = 0; p <= c; p++) {
            int amount = cnt[p][x2][y2]-cnt[p][x1-1][y2]-cnt[p][x2][y1-1]+cnt[p][x1-1][y1-1];
            ans+=((p+t)%(c+1))*amount;
        }
        cout << ans << "\n";
    }


    return 0;
}
