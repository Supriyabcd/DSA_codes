#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
  //count subsets of nums array with sum == target
  //given 1 <= nums[i]
  int countSubsets(vector<int> & arr, int target){
    int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        
        for(int i = 0; i < n; i++) dp[i][0] = 1;

        if(arr[0] <= target) dp[0][arr[0]] = 1;
        
        for(int i = 1; i < n; i++){
            for(int sum = 0; sum <= target; sum++){
                int notTake = dp[i-1][sum];
                int take = 0;
                if(arr[i] <= sum){
                    take = dp[i-1][sum - arr[i]];
                }
                dp[i][sum] = notTake + take;
            }
        }
        
        return dp[n-1][target];
  }

//count subsets with of nums array with sum == target
//given 0 <= nums[i]
int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        
        if(arr[0] == 0){
            dp[0][0] = 2;
        } else {
            dp[0][0] = 1;
        }
        
        if(arr[0] <= target && arr[0] != 0){
            dp[0][arr[0]] = 1;
        }
        
        for(int i = 1; i < n; i++){
            for(int sum = 0; sum <= target; sum++){
                int notTake = dp[i-1][sum];
                int take = 0;
                if(arr[i] <= sum){
                    take = dp[i-1][sum - arr[i]];
                }
                dp[i][sum] = notTake + take;
            }
        }
        
        return dp[n-1][target];
    }

//count partitions such that thier diff == given diff D
//given 0 <= arr[i] 
//same solution for target sum where target == d
int findTargetSumWays(vector<int>& arr, int d) {
        int totalSum = 0, n = arr.size();
        for(int i = 0; i < n; i++){
            totalSum += arr[i]; 
        }
        
        int s2 = (totalSum - d)/2;
        if(totalSum < d || (totalSum - d) % 2 ) return false;
        return perfectSum(arr, s2);
}

};
