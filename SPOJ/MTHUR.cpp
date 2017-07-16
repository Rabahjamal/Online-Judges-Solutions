#include <bits/stdc++.h>
using namespace std;
 
const long long INF = 1e18;
vector<int> a(10005), b(10005);
int value (int v, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += abs(a[i] - (b[i] + v));
    }
    return sum;
}
int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
 
        int m;
        cin >> m;
        vector<int>g(m);
        for(int i = 0; i < m; i++) {
            cin >> g[i];
        }
 
        sort(g.begin(), g.end());
        int left = 0, right = g.size() - 1;
        while(right - left > 3) {
            int m1 = left + (right - left) / 3;
            int m2 = right - (right - left) / 3;
            int v1 = value(g[m1], n), v2 = value(g[m2], n);
            if(v1 < v2)
                right = m2;
            else if(v1 > v2)
                left = m1;
            else
                right = m2;
 
        }
 
        long long mn = INF, ans;
        for(int i = left; i <= right; i++) {
            int x = value(g[i], n);
            if(x < mn)
                mn = x, ans = g[i];
        }
 
        cout << ans << endl;
        a.clear();
        b.clear();
    }
    return 0;
}
