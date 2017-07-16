#include <bits/stdc++.h>
using namespace std;
 
long long graph[1000005][3];
long long dp[1000005][3];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    int cnt = 1;
    int n;
    while(cin >> n) {
		if(!n)
			break;
 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3; j++){
                cin >> graph[i][j];
            }
        }
		for(int i = 0; i < n;  i++)
			for(int j = 0;  j < 3; j++)
				dp[i][j] = 0;
 
		dp[n - 1][1] = graph[n - 1][1];
		dp[n - 1][0] = graph[n - 1][0] + dp[n - 1][1];
		dp[n - 1][2] = graph[n - 1][2];
		for(int i = n - 2; i >= 0; i--){
            for(int j = 2; j >= 0; j--) {
                if(j == 0 && i != 0)
                    dp[i][j] = graph[i][j] + min(min(dp[i + 1][j], dp[i + 1][j + 1]), dp[i][j + 1]);
                if(j == 0 && i == 0)
                    dp[i][j] = graph[i][j] + dp[i][j + 1];
                else if(j == 2 && i != n - 2)
                    dp[i][j] = graph[i][j] + min(dp[i + 1][j], dp[i + 1][j - 1]);
                else if(j == 2 && i == n - 2)
                    dp[i][j] = graph[i][j] + dp[i + 1][j - 1];
                else if(j == 1 && i != n - 2)
                    dp[i][j] = graph[i][j] + min(min(min(dp[i + 1][j], dp[i + 1][j - 1]), dp[i + 1][j + 1]), dp[i][j + 1]);
                else if(j == 1 && i == n - 2)
                    dp[i][j] = graph[i][j] + min(min(dp[i + 1][j], dp[i + 1][j - 1]), dp[i][j + 1]);
            }
		}
		cout << cnt << ". " << dp[0][1] << endl;
        cnt++;
    }
    return 0;
}
