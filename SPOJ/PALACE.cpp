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
 
ll Pw(ll a, ll n) {
    if(n==1)
        return a;
    ll p = Pw(a, n/2);
    if(n&1)
        return (p*p*a)%98777;
    else
        return (p*p)%98777;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int k;
    cin >> k;
    while(k--) {
        ll n;
        cin >> n;
        if(n==1||n==2)
            cout << n << endl;
        else
            cout << Pw(2, (n-1)*(n-1)) << endl;
    }
    return 0;
}
