#include<iostream>
#include<vector>
using namespace std;

//implement lower bound
//brute force - linear search
//optimal solution - binary search
int lower_bound(vector<int> &arr, int n, int x){
    int low  = 0, high = n-1;
    int ans = n;
    while(low <= high){
    int mid = (low + high)/2;
    
    if(arr[mid] >=  x){
        ans = mid;
        high = mid -1;
        } else if (arr[mid] > x){
            low = mid + 1;
        }
    }
    return ans;
}

// Function to find floor of x
// n: size of vector
// x: element whose floor is to find
int findFloor(vector<long long> &v, long long n, long long x) {
    long long low  = 0, high = n-1;
    long long ans = -1;
    while(low <= high){
        long long mid = low  + (high - low)/2;
    
        if(v[mid] <=  x){
            low = mid + 1;
            ans = mid;
        } else if (v[mid] > x){
            high = mid - 1;
        }
    }
    return ans;
}

//Nth root of a number 
//brute force - linear search
//T - O(M), S - O(1)
int nthRootBrute(int n, int m){
    int result = -1;

    for(int i = 1; i <= m; i++){
        if(pow(i,n) == m)
            result = i;
        else if(pow(i,n) > m)
            break;
    }

    return result;
}
//optimal solution - binary search
//T - O(log M), S - O(1)
int func(int mid, int n, int m){
    long long ans = 1;
    for(int i = 1; i <= n; i++){
        ans = ans*mid;
        if(ans > m) return 2;
    }     
    if(ans == m) return 1;
    return 0;
}
int nthRoot(int n, int m){
    int low = 1, high  = m;
    while(low <= high){
        int mid = (low + high)/2;
        int midN = func(mid, n , m);
        if(midN == 1){ return mid; }
        else if(midN == 0) low = mid+1;
        else high = mid - 1;
    }
    return -1;
}


//kth element in 2 sorted arrays when merged
//brute force = use 3rd array to merge and traverse and find the kth ele

//better approach - merge sort and two pointers related 
int kthEle(vector<int>& a, vector<int>& b, int k){
    int m = a.size();
    int n = b.size();
    int i = 0, j = 0;
    int cnt = 0, ele = -1;

    while(i < m && j < n){
        if(a[i] > b[j]){
            if(cnt == k-1) ele = b[j];
            cnt++;
            j++;
        } else {
            if(cnt == k-1) ele = a[i];
            cnt++;
            i++;
        }
    }

    while(i < m){
        if (cnt == k - 1) ele = a[i];
        cnt++;
        i++;
    }

    while(j < n){
        if (cnt == k - 1) ele = b[j];
        cnt++;
        j++;
    }
    return ele;
}