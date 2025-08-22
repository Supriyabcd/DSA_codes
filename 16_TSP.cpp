#include<bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>>& cost){
    int n = cost.size();

    if(n == 1) return cost[0][0];

    int N = 1 << n;
    vector<vector<int>> dp(N, vector<int>(n, 0));
    dp[1 << 0][0] = 0;


    for(int mask = 1; mask < N; mask++){
        for(int i = 0; i < n; i++){
            //visit from i to j provided city's with bit = 1 -> cities already visited
            if(!(mask & (1 << i))) continue; //i not visited

            for(int j = 0; j < n; j++){
                if(mask & (1 << j)) continue; //j aalready visited
                dp[mask | 1 << j][j] = min(dp[mask | 1 << j][j], dp[mask][i] + cost[i][j]);
            }
        }
    }
     //from all cities to city 0
        int ans = INT_MAX;
        for(int i = 1; i < n; i++){
            if(dp[N-1][i] != INT_MAX)
                ans = min(ans, dp[N-1][i] + cost[i][0]);
        }
        
        return ans;
}