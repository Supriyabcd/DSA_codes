#include<iostream>
#include<vector>
#include<algorithm>
#include <map>
#include <unordered_map>

using namespace std;

//rotate matrix by 90 degree clockwise
//brute force- use another matrix
//optimal solution
void rotate(vector<vector<int>> &matrix){
    int n = matrix.size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            swap(matrix[j][i], matrix[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
    }
}

//2Sum problem
//brute force 
string twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return "YES";
        }
        mpp[num] = i;
    }
    return "NO";
}
//better approach
string twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return "YES";
        }
        mpp[num] = i;
    }
    return "NO";
}
//optimal solution
string twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}

//sort 0's 1's 2's 
//brute force - sort function
//better solution - freq of each and overwrite on it
//optimal solution - 
void sort_array(int arr[], int n){
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
    if(arr[mid] == 0){
        swap(arr[mid], arr[low]);
        low++;
        mid++;
        }else if (arr[mid] == 1){
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    } 
}

//find next permutation of given array
//brute force - find all permutation, search next one (T=O(n!*n*log(n!)) S=O(n!))
void NextPermutation(vector<int> &arr){
    vector<vector<int>> res;
    permutations(res, arr, 0);
    sort(res.begin(), res.end());

    // Traverse through res and find the next permutation
    for (int i = 0; i < res.size(); i++) {
      
        if (res[i] == arr) {
            if (i < res.size() - 1)
                arr = res[i + 1];
            if (i == res.size() - 1)
                arr = res[0];
            break;
        }
    }
}
// Generates all permutations
void permutations(vector<vector<int>>& res, vector<int>& arr, int idx)
{
    // Base case: if idx reaches the end of the array
    if (idx == arr.size() - 1) {
        res.push_back(arr);
        return;
    }
    // Permutations made by swapping each element
    // starting from index `idx`
    for (int i = idx; i < arr.size(); i++) {
        swap(arr[idx], arr[i]);
        // Recursive call to create permutations
        // for the next element
        permutations(res, arr, idx + 1);
        // Backtracking
        swap(arr[idx], arr[i]);
    }
}

//better approach - find just next one (T=O(n), S=O(1))
void next_permutation(vector<int> &arr){
    int n = arr.size();   // say arr = [1 2 3 6 5 4 ]

    //find pivot index
    int pivot = -1;
    for(int i = n-2; i >= 0; i--){
        if(arr[i] < arr[i+1]){
            pivot = i;  //pivot in eg : i = 2 
            break;
        }
    }

    //if given arr is highest lexicographically
    if(pivot == -1){
        reverse(arr.begin(), arr.end());
        return;
    }

    // find the element from the right that
    // is just greater than pivot
    for (int i = n - 1; i > pivot; i--) {
        if (arr[i] > arr[pivot]) {
            swap(arr[i], arr[pivot]);
            break;
        } //swap [3,4] - arr = [1 2 4 6 5 3]
    }

    // Reverse the elements from pivot + 1 to the 
    // end to get the next permutation
    reverse(arr.begin() + pivot + 1, arr.end()); 
    // arr = [1 2 4 3 5 6] - next premutation of [1 2 3 6 5 4]
    
}
//built-in c++ function (T=O(n), S=O(1))
//next_permutation(arr.begin(), arr.end()) 
//gives the next permutation of arr


//majority ele = occurs > N/2 times
//brute force - going thro array once
//better - hashmap for freq
int majorityElement(vector<int> v) {

    int n = v.size();
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
    }
    for (auto it : mpp) {
        if (it.second > (n / 2)) {
            return it.first;
        }
    }

    return -1;
}

//optimal  - moore voting's algorithm
int majority(vector <int> v){
    int n = v.size();
    int cnt = 0, el;
    for(int i = 0; i < n; i++){
        if(cnt == 0){
            cnt = 1;
            el = v[i];
        } else if (v[i] == el) cnt++;
        else cnt--;
    }

    int cnt1 = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == el) cnt1++;
    }

    if(cnt1 >= n/2) return el;
    else return -1;
} 

//kadane's algo - max sum of a contiguous subarray
//brute force - nested loop
int sumKadane(vector<int> nums){
    int n = nums.size();
    int maxSum = INT_MIN;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i+1; j < n; j++){
            sum += nums[j];
            maxSum = max(sum, maxSum);
        }
    }
    return maxSum;
}

//optimal solution 
int KAdaneAlgo(vector<int>& nums){
    int n = nums.size();
    long long sum = 0;
    long long maxSum = LONG_MIN;

    for(int i = 0; i < n; i++){
        sum += nums[i];

        if(sum > maxSum){
            maxSum = sum;
        }

        if(sum < 0) sum = 0;
    }
    return maxSum;
}

//extended version of above 
//print the subarray as well
vector<int> kadane_algo(vector<int>& nums){
    vector<int> result;
     int n = nums.size();
    long long sum = 0, start;
    long long maxSum = LONG_MIN;
    int ansStart = -1, ansEnd = -1;
    for(int i = 0; i < n; i++){
        if(sum == 0) start = i; 
        sum += nums[i];

        if(sum > maxSum){
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }

        if(sum < 0) sum = 0;
    }
    for(int i = ansStart; i < ansEnd; i++){
        result.push_back(nums[i]);
    }
    return result;
} 

//leaders in a array
//Leader - element > all elements on its right side
//brute force - 2 nested loops
vector<int> leaders_arr(int arr[], int n){
    vector<int> leaders;
    

    return leaders;
}

//optimal solution 
vector<int> arr_leaders(int arr[], int n){
    vector<int> leaders;
    int max = arr[n-1];
    leaders.push_back(max);
    
    for(int i = n-2; i >= 0; i--){
        if(arr[i] >= arr[i+1]){
            if(arr[i] >= max){
                max = arr[i];
                leaders.push_back(max);
            }
        }
    }
    //to get leaders order same as its order in the array
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

//merge two sorted arrays
vector<int> merge(vector<int>& nums1, int m, vector<int>&nums2, int n){
    vector<int> result;
    result.reserve(m + n);
    int i = 0, j = 0;

    while (i < m && j < n) {
        if (nums1[i] <= nums2[j]) {
            result.push_back(nums1[i++]);
        } else {
            result.push_back(nums2[j++]);
        }
    }

    // If there are remaining elements in nums1
    while (i < m) {
        result.push_back(nums1[i++]);
    }

    // If there are remaining elements in nums2
    while (j < n) {
        result.push_back(nums2[j++]);
    }

    return result;
}


//varation to this
//nums1.size = m+n, store final array in nums1
//optimal solution 1
void merge_arr(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // Start from the end of nums1 and nums2
    int i = m - 1; // Last element of the m elements in nums1
    int j = n - 1; // Last element of nums2
    int k = m + n - 1; // Last position of nums1 (which has enough space)

    // Merge from the back to avoid overwriting elements in nums1
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // If there are any remaining elements in nums2, copy them
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }

    // No need to copy remaining elements from nums1 as they are already in place
}

//optimal solution 2 -shell sort


//count inversions
//inversions = pairs where i < j but a[i]>a[j]
//brute force = two loops 
int inversions(int arr[], int n){
    int result;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j])
            result++;
        }
    }
    return result;
}

//optimal solution - merge sort algo
long long int inversionCount(long long arr[], int n){
    
}

//count subarrays with sum k
//brute force - 3 loops
//better soln - 2 loop
int noOfSubarrays(int k, vector<int> nums){
    int cnt = 0; 
    for(int i = 0; i < nums.size(); i++){
        int sum = 0;
        for(int j = i + 1; j < nums.size(); j++){
            sum += nums[j];
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}

//optimal soln - 
int subarraysWithSumK(int k, vector<int> nums){
    int cnt = 0;
    int prefixSum = 0;
    map<int,int> mpp;
    mpp[0] = 1;

    for(int i = 0; i < nums.size(); i++){
        prefixSum += nums[i];
        int remove = prefixSum - k;
        cnt +=mpp[remove];
        mpp[prefixSum]++;
        } 

    return cnt;
}

//set matrix zeroes 
//if an element in the matrix is 0 then you will have to set its entire column and row to 0
//brute force - set rows and columns to -1 in 1st traversal, in next traversal convert to 0
//T - O(n*m*(n+m)) ~ O(n^3), S - O(1)
void setZeroesBrute(vector<vector<int>>& matrix) {
    int m = matrix.size();//row size
    int n = matrix[0].size();//column size
     for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 0){
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
     }
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
}
void markRow(vector<vector<int>>&matrix, int n, int m, int i){
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}
void markCol(vector<vector<int>>& matrix, int n, int m, int j){
    for (int i = 0; i < m; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

//better approach - rowarray, colarray 
//T - O(2*n*m), S - O(n+m)
void setZeroesBetter(vector<vector<int>>& matrix){
    int m = matrix.size();//row size
    int n = matrix[0].size();//column size

    vector<int> row(m, 0);
    vector<int> col(n,0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

//optimal - first row+extracell = rowarray and 1st column = colarray
//T - O(2*n*m), S - O(1) 
void setZeroes(vector<vector<int>>& matrix){
    int m = matrix.size();//row size
    int n = matrix[0].size();//column size

    // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]
    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}