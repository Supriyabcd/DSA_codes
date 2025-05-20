#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

         vector<bool> no_friend_with_prev(n , false); 
        // If no_friend_with_prev[i] is true, then i doesn't know i+1

        for(int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            if(x > y) swap(x, y); // Ensure x < y
            if(y == x+1)
            {
                no_friend_with_prev[y] = true;
                no_friend_with_prev[x] = true;
            }
        }

        // Count the number of good subsegments
        int left = 0;
        long long result = 0;
        
        while (left < n) {
            int right = left;
            while (right < n && !no_friend_with_prev[right]) {
                right++;
            }
            int len = right - left;
            result += (long long)len * (len + 1) / 2;
            left = right + 1;

        }
        /*int min_end = n, max_start = 1;
        
        for(int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            max_start = max(max_start, x);
            min_end = min(min_end, y);
        }
        
        // Calculate the number of good subsegments
        int good_subsegments = max(0, min_end - max_start + 1);
        int result = (n * (n + 1)) / 2 - (good_subsegments * (good_subsegments + 1)) / 2;

        cout << result << endl;
    }*/
    cout << result <<endl;
    }
} 