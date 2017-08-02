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

ll arr[100001];

ll pw(ll a, ll n) {
    if(n==1)
        return a;
    ll p = pw(a, n/2);
    if(n&1)
        return p*p*a;
    else
        return p*p;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, x, y, s;
    cin >> n >> x >> y;
    fill(arr, arr+n-1, 1);
    arr[n-1] = y-n+1;
    if(arr[n-1]<=0) {
        cout << -1 << endl;
        return 0;
    }
    ll val = pw(arr[n-1], 2)+n-1;
    if(val>=x) {
        for(int i = 0; i < n; i++) {
            cout << arr[i] << "\n";
        }
    }
    else {
        cout << -1 << "\n";
    }

    return 0;
}
