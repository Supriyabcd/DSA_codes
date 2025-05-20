#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canWePlace(vector<int>& arr, int dist, int k, int n){
    int cntCows = 1;
    int last = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] - last >= dist){
            cntCows++;
            last = arr[i];
        }
        if(cntCows >= k) return true;
    }
    return false;
}
int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> arr;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        int  l = 0, h = arr[n-1]-arr[0];

        while(l <= h){
            int mid = l + (h-l)/2;
            if(canWePlace(arr, mid, k, n)){
                int ans = mid;
                l = mid+1;
            } else {
                h = mid-1;
            }
        }
        cout << h << endl;
    }
    return 0;
}