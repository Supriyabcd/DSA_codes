#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution{
    public:
/* #1 robot on an m x n grid. initially located at the top-left corner (i.e., grid[0][0]). 
tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
can only move either down or right at any point in time.
Given the two integers m and n, 
return the number of possible unique paths that the robot can take to reach the bottom-right corner.*/

    //brute force: recursion(top-down approach)
    //TC : O(2^(n*m)), SC: O(m + n) due to recursion stack depth in the worst case
    int uniquePaths_r(int i, int j){
        
        //Base case:
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;

        int paths = uniquePaths_r(i , j - 1) + uniquePaths_r(i - 1, j);
        
        return paths;
    }

    //memoization : bottom-up approach
    //TC : O(m * n) SC: O(m * n)
    int uniquePaths_memo(int i, int j, vector<vector<int>>& dp){
        //Base case:
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        dp[i][j] = uniquePaths_memo(i , j - 1, dp) + uniquePaths_memo(i - 1, j, dp);
        
        return dp[i][j];
    }

    //function that calls other functions
    int UniquePaths(int m, int n){

        int recusive_soln = uniquePaths_r(m-1 , n-1);

        vector<vector<int>> dp(m , vector<int>(n , -1));
        int memo_soln = uniquePaths_memo(m-1, n - 1, dp);

        //tabulation soln
        dp.assign(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;

                int up = 0, left = 0;    
                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];
                
                dp[i][j] = up + left;
            }
        }

        int tabul_soln = dp[m-1][n-1];

        //space optimization soln 
        vector<int> prev(n , 0);

        for(int i = 0; i < m; i++){
            vector<int> curr(n , 0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) 
                    curr[j] = 1;
                else
                    curr[j] = prev[j] + curr[j-1];
            }
            prev = curr;
        }
        return prev[n-1];
    }

/* #2 grid with obstacles*/

/* #3 min moves with some teleportation ports*/
};