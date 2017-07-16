#include <bits/stdc++.h>
using namespace std;
 
vector<pair <pair<int, int>, pair<int, int> > >score;
bool compare( const pair<pair<int, int> , pair<int, int> >& i, const pair<pair<int, int>, pair<int, int> >& j ) {
    if( i.first.first < j.first.first ) return false;
    if( i.first.first > j.first.first ) return true;
    return j.second.first > i.second.first;
}
 
bool valid1(int mid) {
    for(int i = 0; i < score.size() - 1; i++) {
        if(score[i].first.first == score[i + 1].first.first && score[i].second.first < score[i + 1].second.first) {
            int fst = score[i].first.second + score[i].second.second * mid;
            int scd = score[i + 1].first.second + score[i + 1].second.second * mid;
            if(fst >= scd)return false;
        }
        else if(score[i].first.first == score[i + 1].first.first && score[i].second.first == score[i + 1].second.first) {
            int fst = score[i].first.second + score[i].second.second * mid;
            int scd = score[i + 1].first.second + score[i + 1].second.second * mid;
            if(fst != scd)return false;
        }
    }
    return true;
}
 
int b_s1(int st, int e) {
    while(st < e) {
        int mid = st + (e - st + 1) / 2;
        if(valid1(mid)) {
            st = mid;
        }
        else {
            e = mid - 1;
        }
    }
    return st;
}
 
bool valid2(int mid) {
    for(int i = 1; i < score.size(); i++) {
        if(score[i].first.first == score[i - 1].first.first && score[i].second.first > score[i - 1].second.first) {
            int fst = score[i].first.second + score[i].second.second * mid;
            int scd = score[i - 1].first.second + score[i - 1].second.second * mid;
            if(fst <= scd)return false;
        }
        else if(score[i].first.first == score[i - 1].first.first && score[i].second.first == score[i - 1].second.first) {
            int fst = score[i].first.second + score[i].second.second * mid;
            int scd = score[i - 1].first.second + score[i - 1].second.second * mid;
            if(fst != scd)return false;
        }
    }
    return true;
}
 
int b_s2(int st, int e) {
    while(st < e) {
        int mid = (st + (e - st) / 2);
        if(valid2(mid)) {
            e = mid;
        }
        else {
            st = mid + 1;
        }
    }
    return st;
}
int main()
{
    int t, p;
    while (cin >> t >> p) {
        if(!t && !p)break;
 
        for(int i = 0; i < t; i++) {
            int solved = 0, pen = 0, f = 0, time = 0;
            for(int j = 0; j < p; j++) {
                int a;
                char ch, s[5];
                cin >> a >> ch >> s;
                if(s[0] != '-') {
                    pen += (atoi(s) + (a - 1) * 20);
                    f += (a-1);
                    time += atoi(s);
                    solved++;
                }
            }
            score.push_back(make_pair(make_pair(solved, time), make_pair(pen, f)));
        }
 
        sort(score.begin(), score.end(), compare);
        int l = b_s2(1, 20), r = b_s1(l, 1e6);
        if(r == 1e6)
            cout << l << " *" << endl;
        else
            cout << l << " " << r << endl;
 
        score.clear();
    }
    return 0;
}
