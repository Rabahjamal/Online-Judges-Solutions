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

int grid[2018][2*2018];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int cnt=1;
    map<int, set<int> >mp;
    for(int i=0; i<n; i++) {
        for(int j=0; j<x; j++) {
            grid[i][j]=cnt;
            mp[i].insert(cnt++);
        }
    }
    map<int, set<int> >::iterator it=mp.begin();
    for(int i=0; i<n; i++) {
        for(int j=x; j<2*x; j++) {
            bool f=0;
            for(; it!=mp.end(); it++) {
                if(it->F!=i&&!it->S.empty()) {
                    grid[i][j]=*(it->S.begin());
                    it->S.erase(*(it->S.begin()));
                    f=1;
                    it++;
                    if(it==mp.end())
                        it=mp.begin();
                    break;
                }
            }
            if(!f) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<2*x; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
