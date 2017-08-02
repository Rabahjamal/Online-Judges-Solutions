#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()


int main()
{
    int n;
    cin >> n;
    vector<int>v(n);
    map<int, int>mp;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        mp[v[i]]++;
    }
    int m;
    cin >> m;
    vector<int>p(m), s(m);
    for(int i = 0; i < m; i++)
        cin >> p[i];
    for(int i = 0; i < m; i++)
        cin >> s[i];

    vector<pair<int,int> >res;
    int ans=1, val = 0;
    for(int i = 0; i < m; i++){
        if(mp.find(p[i]) != mp.end()){
            if(mp[p[i]] >= val)
                res.push_back(make_pair(mp[p[i]], i)), val = mp[p[i]], ans = i + 1;
        }
    }
    sort(rall(res));
    if(res.size() >=2 && res[0].first == res[1].first){
        int x = res[0].first;
        int i = 0;
        int mx = 0;
        while(i < res.size()&&res[i].first == x){
            if(mp.find(s[res[i].second]) != mp.end()){
                if(mp[s[res[i].second]] >= mx)
                    mx = mp[s[res[i].second]], ans = res[i].second+1;
            }
            i++;
        }
		if(mx == 0)
			ans = res[0].second+1;
    }
	else if(res.size() == 0)
	{
		val = 0;
		for(int i = 0; i < m; i++){
			if(mp.find(s[i]) != mp.end()){
				if(mp[s[i]] >= val)
					val = mp[s[i]], ans = i+1;
			}
		}	
		if(val == 0)
			ans =1;
	}
	
    cout << ans << endl;
    return 0;
}
