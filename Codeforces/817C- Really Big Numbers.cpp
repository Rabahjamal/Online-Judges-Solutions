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

bool ok(ll a, ll b) {
    ll s=0, t=a;
    while(t) {
        s+=t%10;
        t/=10;
    }
    return (a-s>=b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, s;
    cin >> n >> s;

    ll start=1, end=n+1;
    while(start < end) {
        ll mid = (start+(end-start)/2);
        if(ok(mid, s))
            end=mid;
        else
            start=mid+1;
    }
    cout << n-start+1 << endl;
    return 0;
}
