#include<bits/stdc++.h>
using namespace std;

//n^Cr caluculation
int nCr(int n, int r){
    long long result;

    for(int i = 0; i < r; i++){
        result = result*(n-i);
        result = result/(i+1);
    }
    return result;
}

//Pascal's triangle

//type 1 - find element in the pascal triangle given row no.  and col no.
//arguments passed will be int row-1, int col-1
//brute force = use nCr formula - find fac. n, r, n-r and compute 
//tc = O(n*r*n-r), sc = O(1)
//better solution - tc = O(col_1); sc = O(1)
int findPascalEle(int row_1, int col_1){
    int res = 1;
    for(int i = 0; i < col_1; i++){
        res = res*(row_1-i);
        res = res/(i+1);
    }
    return res;
}

//type 2: find elements of the given row 
//number of elements in a row = row no.
//brute force = use type1 func to find each of the elemnts in the row
//better solution => TC = O(row_no)
vector<int> findPascalRow(int row_no){
    vector<int> res;
    int ans = 1;
    res.push_back(ans);
    for(int i = 1; i < row_no; i++){
        ans = ans*(row_no-i);
        ans = ans/i;
        res.push_back(ans);
    }
    return res;
}

//type 3: print first n row of Pascal Triangle, given n
//brute force : use nCr formula and loops 
//better : use type 1's function 
//TC = O(r*r*c)
vector<vector<int>> findPascalTriangle(int n){
    vector<vector<int>> res;
    for(int i = 1; i <= n; i++){
        vector<int> templis;
        for(int j = 1; j <= i; j++){
            templis.push_back(findPascalEle(i-1,j-1));
        }
        res.push_back(templis);
    }
    return res;
}
//optimal solution : use type 2's function 
vector<vector<int>> findPascalTri(int numRows){
    vector<vector<int>> res;
    vector<int> templis;
    for(int i = 1; i <= numRows; i++){
        templis = findPascalRow(i);
    }
    res.push_back(templis);
    return res;
}

//3sum - triplets that add upto target
//brute force = 3 loops
//better approach = 2 loops, 3rd ele = target - loop ele sum
//optimal solution - 3 pointers
vector<vector<int>> triplets(int target, vector<int> &arr){
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = arr.size() - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < target) {
                j++;
            }
            else if (sum > target) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}

//merging overlapping subintervals
//brute-force
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) { // select an interval:
        int start = arr[i][0];
        int end = arr[i][1];

        //Skip all the merged intervals:
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        //check the rest of the intervals:
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                end = max(end, arr[j][1]);
            }
            else {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

//optimal solution
vector<vector<int>> mergeOverlapInterval(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

//maximum product subarray
//brute force - nested loops
int maxSubarrProd(vector<int>arr){
    int n = arr.size();

    int result = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int prod = 1;
            for(int k = i; k <= j; k++) 
                prod *= arr[k];
            result = max(result,prod);
        }
    }
    return result;
}

//better approach
int maxProductSubArray(vector<int>& nums) {
    int result = nums[0];
    for(int i = 0; i < nums.size()-1; i++) {
        int p = nums[i];
        for(int j = i+1; j < nums.size(); j++) {
           result = max(result,p);
           p *= nums[j];
        }
        result = max(result,p);//manages (n-1)th term 
    }
    return result;
}
 
//optimal solution 1
int maxProdSubAr(vector<int> &arr) {
    int n = arr.size(); //size of array.

    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= arr[i];
        suff *= arr[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

//optimal solution 2
//using kadane's algorithm

int main(){

    return 0;

}