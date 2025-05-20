#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        int win = 0;
        if(a1 > b1){
            win++;
        } else if (a1 > b2){
            win++;
        }
        if (a2 > b2){
            win++;
        } else if(a2  > b1){
            win++;
        }
        cout << win << endl;
    }
    return 0;
} 