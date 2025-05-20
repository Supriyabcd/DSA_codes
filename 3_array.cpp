#include<bits/stdc++.h>
using namespace std;

//finding largest element
//Brute force - sort array in ascending order, largest = last

//Recursive - using max variable;
int findLargestElement(int arr[], int n) {
 
  int max = arr[0];
  for (int i = 0; i < n; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}

//find second largest w/o sorting
//not optimal solution - O()
void getElements(int arr[],int n)
{
    if(n==0 || n==1)
        cout<<-1<<" "<<-1<<endl;  // edge case when only one element is present in array
    int small=INT_MAX,second_small=INT_MAX;
    int large=INT_MIN,second_large=INT_MIN;
    int i;
    for(i=0;i<n;i++)
    {
        small=min(small,arr[i]);
        large=max(large,arr[i]);
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]<second_small && arr[i]!=small)
            second_small=arr[i];
        if(arr[i]>second_large && arr[i]!=large)
            second_large=arr[i];
    }

    cout<<"Second smallest is "<<second_small<<endl;
    cout<<"Second largest is "<<second_large<<endl;
}

//optimal solution - O(N) - but lesser no. of passes
int secondSmallest(int arr[],int n)
{
    if(n<2)
        return -1;
    int small = INT_MAX;
    int second_small = INT_MAX;
    int i;
    for(i = 0; i < n; i++) 
    {
       if(arr[i] < small)
       {
          second_small = small;
          small = arr[i];
       }
       else if(arr[i] < second_small && arr[i] != small)
       {
          second_small = arr[i];
       }
    }
   return second_small;     
}
int secondLargest(int arr[],int n)
{
	if(n<2)
	return -1;
    int large=INT_MIN,second_large=INT_MIN;
    int i;
    for (i = 0; i < n; i++) 
    {
        if (arr[i] > large) 
        {
            second_large = large;
            large = arr[i];
        }
 
        else if (arr[i] > second_large && arr[i] != large) 
        {
            second_large = arr[i];
        }
    }
    return second_large;                
}

//removing duplicates
//brute force = hash set
int removeDuplicates(int arr[], int n) {
  set <int> set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  return k;
}

//optimal solution
int removeDuplicates(int arr[], int n)
{
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}

//check if array is sorted
//optimal solution
bool isSorted(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1])
      return false;
  }

  return true;
}

//left rotate array by one place
//optimal solution
void leftRotatebyOne(int arr[], int n){
    int x = arr[0];
    for(int i = 0; i < n-1; i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = x;
}

//right rotate by k elements
//brute force
void rotate(vector<int>& nums, int k) {
        int x;
        int n = nums.size();
        while(k){
            x = nums[n-1];
            for(int i = n-1; i > 0; i--){
            nums[i] = nums[i-1]; 
            }
            nums[0] = x;
            k--;
        }
    }

//optimal solution
void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        // Reduce k in case it's larger than the size of the array
        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin() + k);

        reverse(nums.begin()+k, nums.end());

}

//union of arrays
//optimal solution
vector <int> UnionArray(int arr1[], int arr2[], int n, int m){
  vector <int> Union;
  int i = 0, j = 0;
  while(i <= n && j <= m){
    if(arr1[i] < arr2[j]){
      if(Union.empty()|| Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    } else if (arr1[i] > arr2[j]) {
        if(Union.empty() || Union.back() != arr2[j])
          Union.push_back(arr2[j]);
        j++;
    } else {
        if (Union.empty() || Union.back() != arr1[i]) {
                Union.push_back(arr1[i]);
            }
            i++;
            j++;
      }      
    }   
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}

//find missing no. in 1 to N
//brute force = linear search for each no.
//better approach = hashing, freq of missing=0 else 1
//optimal solution1 = using summation
int missing_no(int arr[], int n){
    int sum1 = n*(n+1)/2;
    int sum2 = accumulate(arr, arr+n, 0);

    return (sum1-sum2);

}

//optimal solution = using XOR
//also an optimal soln for find no that 
//occurs once where other ele occur twice
int missingNo(int arr[], int n){
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < n - 1; i++) {
        xor2 = xor2 ^ arr[i]; // XOR of array elements
        xor1 = xor1 ^ (i + 1); //XOR up to [1...N-1]
    }
    xor1 = xor1 ^ n; //XOR up to [1...N]

    return (xor1 ^ xor2); // the missing number
}


//max. consecutive 1's
int maxConsecutiveOnes(int arr[], int n){
    int cnt = 0, max_cnt = 0;
    
    for(int i = 0; i < n; i++){
      if(arr[i]==1){
        cnt++;
        if(cnt > max_cnt)
          max_cnt = cnt;
      }
    }
      return max_cnt;
}

//longest subarray with given sum K
//brute force - using two loops
int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        for (int j = i; j < n; j++) { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            long long s = 0;
            for (int K = i; K <= j; K++) {
                s += a[K];
            }

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}
//better approach - hashing
int longestSubArr(vector<int>& arr, long long k){
    int n = arr.size(); // size of the array.
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        //sum of remining part = current_sum - k
        long long rem = sum - k;

        //length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

//optimal approach - two pointers
int getLongestSubarray(vector<int>& arr, long long k){


}