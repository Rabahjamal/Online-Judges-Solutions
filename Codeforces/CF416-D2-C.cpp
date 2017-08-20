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

bool took[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector< pair<int, int> >V(n);
    map< pair<int, int>, set<int> >mp;
    for(int i=0; i<n; i++) {
        cin >> V[i].S >> V[i].F;
        mp[{V[i].S, V[i].F}].insert(i+1);
    }
    int k;
    cin >> k;
    vector<int>T(k);
    for(int i=0; i<k; i++) {
        cin >> T[i];
    }
    sort(rall(V));
    int m=0, s=0;
    vector< pair<int, int> >ans;
    for(int i=0; i<n; i++) {
        int mn=inf, ind=-1;
        for(int j=0; j<k; j++) {
            int x=T[j], y=V[i].S;
            if(T[j]>=V[i].S&&!took[j]){
                if(T[j]<=mn)
                    mn=T[j], ind=j+1;
            }
        }
        if(ind!=-1) {
            ans.push_back({*(mp[{V[i].S, V[i].F}].begin()), ind});
            took[ind-1]=1;
            mp[{V[i].S, V[i].F}].erase(*(mp[{V[i].S, V[i].F}].begin()));
            if(mp[{V[i].S, V[i].F}].empty())
                mp.erase({V[i].S, V[i].F});
            s+=V[i].F;
        }
    }
    cout << ans.size() << " " << s << "\n";
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i].F << " " << ans[i].S << "\n";
    }
    return 0;
}
