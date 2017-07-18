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

vector<unsigned int>primes;

bool isPrime(unsigned int n) {
    if(n==2)
        return 1;
    if(n==0||n==1||n%2==0)
        return 0;
    for(int i=0; i<primes.size(); i++) {
        if(n%primes[i]==0 && n!=primes[i])
            return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool>check(70000, 1);
    check[0]=0,check[1]=0;
    unsigned int lim=4294967296;
    for(unsigned int i=2; i*i <= lim; i++) {
        if(check[i]) {
            for(unsigned int j=i*2; j*j<=lim; j+=i)
                check[j]=0;
        }
    }
    for(int i=0; i<check.size(); i++) {
        if(check[i])
            primes.push_back(i);
    }
    int k;
    cin >> k;
    while(k--) {
        unsigned int N;
        cin >> N;
        for(unsigned int i=N-1; i>=2; i--) {
            if(isPrime(i)) {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}
