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

int main()
{
    string str;
    cin >> str;
    vector<ll>save;

    for(ll i = 0; i <=999999; i++){
        save.push_back(i * 8);
    }

    for(int i = 0; i < save.size(); i++){
        char num[15];
        itoa(save[i], num, 10);
        int cnt = 0;
        for(int k = 0; k < str.size(); k++){
            if(str[k] == num[cnt])cnt++;
        }
        if(cnt == strlen(num)){
            cout << "YES" << endl << num << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
