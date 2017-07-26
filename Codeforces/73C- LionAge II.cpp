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

string s;
int dp[101][27][101];
map<pair<char, char>, int>MP;

int solve(int idx,char prv,int k){
    if(idx==s.size())
        return 0;
    int &ret=dp[idx][prv-97][k];
    if(ret!=-1)
        return ret;
    int a=solve(idx+1,s[idx],k)+MP[{prv,s[idx]}];
    int b=-inf;
    for(int i=0; i<26; i++){
        if(i+97!=s[idx]&&k>0)
            b=max(b,solve(idx+1,i+97,k-1)+MP[{prv,i+97}]);
    }
    return ret=max(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k, n;
    cin>>s>>k>>n;
    for(int i=0; i<n; i++){
        char x, y;
        int c;
        cin>>x>>y>>c;
        MP[{x, y}]=c;
    }
    memset(dp, -1, sizeof dp);
    cout<<solve(0,'{',k)<<endl;
    return 0;
}
