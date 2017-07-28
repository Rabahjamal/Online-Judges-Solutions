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


void get_divisors(int n) {
    for(int i = 1; i * i <= n; i++) {
        if(n%i==0)
            cout << i << " " << n/i << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    string n;
    cin >> a >> n;
    vector<int>V;
    for(int i = 0; i < n.size(); i++) {
        if(n[i]=='2')
            V.push_back(2);
        else if(n[i]=='3')
            V.push_back(3);
        else if(n[i]=='4')
            V.push_back(2), V.push_back(2), V.push_back(3);
        else if(n[i]=='5')
            V.push_back(5);
        else if(n[i]=='6')
            V.push_back(3), V.push_back(5);
        else if(n[i]=='7')
            V.push_back(7);
        else if(n[i]=='8')
            V.push_back(2), V.push_back(2), V.push_back(2), V.push_back(7);
        else if(n[i]=='9')
            V.push_back(7), V.push_back(3), V.push_back(3), V.push_back(2);
    }
    sort(rall(V));
    for(int i=0; i<V.size(); i++) {
        cout << V[i];
    }
    return 0;
}
