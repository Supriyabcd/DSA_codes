#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Recursive approach:
// Matrix Ai has dimension arr[i-1] x arr[i]
int minMultRec1(vector<int> &arr, int i, int j)
{

    // If there is only one matrix
    if (i + 1 == j)
        return 0;

    int res = INT_MAX;

    // Place the first bracket at different
    // positions or k and for every placed
    // first bracket, recursively compute
    // minimum cost for remaining brackets
    // (or subproblems)
    for (int k = i + 1; k < j; k++)
    {
        int curr = minMultRec1(arr, i, k) + minMultRec1(arr, k, j) + arr[i] * arr[k] * arr[j];

        res = min(curr, res);
    }

    // Return minimum count
    return res;
}
int matrixMultiplication1(vector<int> &arr)
{

    int n = arr.size();
    return minMultRec1(arr, 0, n - 1);
}

//memoization:
int minMultRec2(vector<int> &arr, int i, int j, vector<vector<int>> &memo)
{

    // If there is only one matrix
    if (i + 1 == j)
        return 0;

    // Check if the result is already ;computed
    if (memo[i][j] != -1)
        return memo[i][j];

    int res = INT_MAX;

    // Place the first bracket at different positions or k and
    // for every placed first bracket, recursively compute
    // minimum cost for remaining brackets (or subproblems)
    for (int k = i + 1; k < j; k++)
    {
        int curr = minMultRec2(arr, i, k, memo) + minMultRec2(arr, k, j, memo) + arr[i] * arr[k] * arr[j];

        res = min(curr, res);
    }

    // Store the result in memo table
    memo[i][j] = res;
    return res;
}

int matrixMultiplication2(vector<int> &arr)
{

    int n = arr.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return minMultRec2(arr, 0, n - 1, memo);
}

//tabulation: 
int matrixMultiplication(vector<int> &arr)
{

    int n = arr.size();

    // Create a 2D DP array to store the minimum
    // multiplication costs
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill the DP array.
    // Here, len is the chain length
    for (int len = 2; len < n; len++)
    {
        for (int i = 0; i < n - len; i++)
        {
            int j = i + len;
            dp[i][j] = INT_MAX;

            for (int k = i + 1; k < j; k++)
            {
                int cost = dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    // The minimum cost is stored in dp[0][n-1]
    return dp[0][n - 1];
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    int res = matrixMultiplication(arr);
    cout << res << endl;
    return 0;
}
