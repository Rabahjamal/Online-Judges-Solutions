#include <bits/stdc++.h>
using  namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

int main()
{
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    vector<pair<int, char> >vp(m);

    for(int i = 0; i < m; i++){
        cin >> vp[i].first >> vp[i].second;
    }

    bool x = 0;
    int numOfIntervals = 0, len = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == '.')len++;
        if(str[i] == '.' && !x){
            x = 1;
            numOfIntervals++;
        }
        else if(str[i] != '.' && x){
            x = 0;
        }
    }

    for(int i = 0; i < m; i++){
        if(vp[i].second == '.' && str[vp[i].first - 1] != '.'){
            if(vp[i].first > 1 && vp[i].first < n){
                if(str[vp[i].first-2] == '.' && str[vp[i].first] == '.')
                    len++, numOfIntervals--, str[vp[i].first - 1] = '.';
                else if(str[vp[i].first-2] != '.' && str[vp[i].first] != '.')
                    len++, numOfIntervals++, str[vp[i].first - 1] = '.';
                else if(str[vp[i].first-2] == '.' || str[vp[i].first] == '.')
                    len++, str[vp[i].first - 1] = '.';
            }
            else if(vp[i].first == 1){
                if(str[vp[i].first] == '.')
                    len++, str[vp[i].first - 1] = '.';
                else
                    len++, numOfIntervals++, str[vp[i].first - 1] = '.';
            }
            else{
                if(str[vp[i].first - 2] == '.')
                    len++, str[vp[i].first - 1] = '.';
                else
                    len++, numOfIntervals++, str[vp[i].first - 1] = '.';
            }
        }
        else if(vp[i].second != '.' && str[vp[i].first - 1] == '.'){
            if(vp[i].first > 1 && vp[i].first < n){
                if(str[vp[i].first-2] == '.' && str[vp[i].first] == '.')
                    len--, numOfIntervals++, str[vp[i].first - 1] = vp[i].second;
                else if(str[vp[i].first-2] != '.' && str[vp[i].first] != '.')
                    len--, numOfIntervals--, str[vp[i].first - 1] = vp[i].second;
                else if(str[vp[i].first-2] != '.' || str[vp[i].first] != '.')
                    len--, str[vp[i].first - 1] = vp[i].second;
            }
            else if(vp[i].first == 1){
                if(str[vp[i].first] == '.')
                    len--, str[vp[i].first - 1] = vp[i].second;
                else
                    len--, numOfIntervals--, str[vp[i].first - 1] = vp[i].second;
            }
            else{
                if(str[vp[i].first - 2] == '.')
                    len--, str[vp[i].first - 1] = vp[i].second;
                else
                    len--, numOfIntervals--, str[vp[i].first - 1] = vp[i].second;
            }
        }
        cout << len - numOfIntervals << endl;
    }
    return 0;
}
