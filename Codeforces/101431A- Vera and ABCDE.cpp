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

char grid[5][2017*3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int cur=0;
    char A[5][3]={{'*','*','*'},{'*','.','*'},{'*','*','*'},{'*','.','*'},{'*','.','*'}};
    char B[5][3]={{'*','*','*'},{'*','.','*'},{'*','*','*'},{'*','.','*'},{'*','*','*'}};
    char C[5][3]={{'*','*','*'},{'*','.','.'},{'*','.','.'},{'*','.','.'},{'*','*','*'}};
    char D[5][3]={{'*','*','*'},{'*','.','*'},{'*','.','*'},{'*','.','*'},{'*','*','*'}};
    char E[5][3]={{'*','*','*'},{'*','.','.'},{'*','*','*'},{'*','.','.'},{'*','*','*'}};
    for(int i=0; i<n; i++) {
        if(s[i]=='A') {
            for(int i=0; i<5; i++) {
                int x=0;
                for(int j=cur; j<cur+3; j++) {
                    grid[i][j]=A[i][x++];
                }
            }
            cur+=3;
        }
        else if(s[i]=='B') {
            for(int i=0; i<5; i++) {
                int x=0;
                for(int j=cur; j<cur+3; j++) {
                    grid[i][j]=B[i][x++];
                }
            }
            cur+=3;
        }
        else if(s[i]=='C') {
            for(int i=0; i<5; i++) {
                int x=0;
                for(int j=cur; j<cur+3; j++) {
                    grid[i][j]=C[i][x++];
                }
            }
            cur+=3;
        }
        else if(s[i]=='D') {
            for(int i=0; i<5; i++) {
                int x=0;
                for(int j=cur; j<cur+3; j++) {
                    grid[i][j]=D[i][x++];
                }
            }
            cur+=3;
        }
        else {
            for(int i=0; i<5; i++) {
                int x=0;
                for(int j=cur; j<cur+3; j++) {
                    grid[i][j]=E[i][x++];
                }
            }
            cur+=3;
        }
    }
    for(int i=0; i<5; i++) {
        for(int j=0; j<n*3; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}
