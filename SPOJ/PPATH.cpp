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
 
vector<vector<int> > adj(100005);
int dist[100005];
bool vis[100005];
 
bool isPrime(int n) {
    if(n == 2)
        return true;
    if(n == 1 || n % 2 == 0)
        return false;
    for(int i = 3; i*i <= n; i+=2) {
        if(n%i == 0)
            return false;
    }
    return true;
}
 
bool oneDig(int a, int b) {
    int cnt = 0;
    while(a) {
        int x = a%10;
        int y = b%10;
        if(x==y)cnt++;
        a/=10, b/=10;
    }
    return (cnt==3);
}
 
void bfs(int start) {
    queue<int>q;
    q.push(start);
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        vis[top] = 1;
        for(int i = 0; i < adj[top].size(); i++) {
            int node = adj[top][i];
            if(dist[top]+1 < dist[node])
                dist[node] = dist[top]+1;
            if(!vis[node]) {
                q.push(node);
            }
        }
    }
 
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int>primes;
    for(int i = 1001; i <= 9999; i+=2) {
        if(isPrime(i))
            primes.push_back(i);
    }
    for(int i = 0; i < primes.size(); i++) {
        for(int j = i+1; j < primes.size(); j++) {
            if(oneDig(primes[i], primes[j])) {
                adj[primes[i]].push_back(primes[j]);
                adj[primes[j]].push_back(primes[i]);
            }
        }
    }
    while(t--) {
        int a, b;
        cin >> a >> b;
        for(int i = 0; i < primes.size(); i++) {
            dist[primes[i]] = inf;
            vis[primes[i]] = 0;
        }
        dist[a] = 0;
        bfs(a);
        if(dist[b] != inf)
            cout << dist[b] << "\n";
        else
            cout << "Impossible\n";
    }
 
    return 0;
}
