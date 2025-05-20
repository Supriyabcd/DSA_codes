#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        
        long long r;
        cin >> r; 
        int cnt = 0;

        for(int i = 0; i <= r; i++){
            for(int j = 0; j <= r; j++){
                if (sqrt(i*i + j*j) < r+1 && sqrt(i*i + j*j) >= r){
                    if (i == 0 || j == 0) {
                        cnt += 2; }
                    else {cnt += 4;}
                }
            }
        }

        cout << cnt << endl;
    }
}