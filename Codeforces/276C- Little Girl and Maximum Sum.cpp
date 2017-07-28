#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<long long>v(n), save(n), a(n+1);
    vector<pair<long long, long long> >vp(q);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    for(int i = 0; i < q; i++){
        cin >> vp[i].first >> vp[i].second;
        a[vp[i].first - 1]++;
        a[vp[i].second]--;
    }

    save[0] = a[0];
    for(int i = 1; i < n; i++){
        save[i] = a[i] + save[i - 1];
    }
    sort(save.rbegin(), save.rend());
    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans += v[i] * save[i];
    }
    cout << ans << endl;
    return 0;
}
