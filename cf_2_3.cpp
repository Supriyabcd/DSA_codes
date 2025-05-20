#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, s, m;
        cin >> n >> s >> m;

        vector<pair<int, int>> lr(n);
        for(int i = 0; i < n; i++){
            if (i == 0 ){
                cin >> lr[i].first >> lr[i].second;
            }
            if(i > 1 && lr[i].first > lr[i-1].second ){
                cin >> lr[i].first >> lr[i].second;
            }
        }
        if ((lr[0].first - 0) > s || (m - lr[n-1].second) > s ){
            cout << "YES" << endl;
        } else for(int i = 0; i < n; i++){
            if ((lr[i].first - lr[i-1].second) > s)
                cout << "YES " <<endl;
            else{
            cout << "NO" << endl;}
        }
    }
    return 0;
}