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

int a[1005];
int dp[1005][1005], n;

int solve(int i, int j){
    if(j>=n)
        return a[i];
    int &ret=dp[i][j];
    if(ret!=-1)
        return ret;
    int A=solve(j+1, j+2)+max(a[i], a[j]);
    int B=solve(j, j+2)+max(a[i], a[j+1]);
    int C=solve(i, j+2)+max(a[j], a[j+1]);
    return ret=min(A, min(B, C));
}

void build(int i, int j){
    if(j>=n && n&1){
        cout << i+1 << endl;
        return;
    }
    else if(j>=n)
        return;
    int A=solve(j+1, j+2);
    int B=solve(j, j+2);
    int C=solve(i, j+2);
    int cur=solve(i, j);
    if(A+max(a[i], a[j])==cur){
        cout << i+1 << " " << j+1 << endl;
        build(j+1, j+2);
    }
    else if(B+max(a[i], a[j+1])==cur){
        cout << i+1 << " " << j+2 << endl;
        build(j, j+2);
    }
    else {
        cout << j+1 << " " << j+2 << endl;
        build(i, j+2);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    memset(dp, -1, sizeof dp);
    int ans=solve(0, 1);
    cout << ans << endl;
    build(0, 1);
    return 0;
}
