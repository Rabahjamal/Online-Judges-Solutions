#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool compare(const pair<ll, ll> &l, const pair<ll, ll> &r) {

    return l.second < r.second;

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, r, avg, sum = 0;
    cin >> n >> r >> avg;
    vector<pair<ll, ll> >a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        sum += a[i].first;
    }

    ll missed = (n * avg) - sum, ans = 0, i = 0;
    sort(a.begin(), a.end(), compare);

    while(missed > 0) {
        if(i >= n)break;
        ll x = r - a[i].first;
        if(x <= missed) {
            ans += x * a[i].second;
            missed -= x;
        }
        else if(x > missed) {
            ans += missed * a[i].second;
            missed = 0;
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}
