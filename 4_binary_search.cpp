#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

//implement lower bound
//brute force - linear search
//optimal solution - binary search
int lower_bound(vector<int> &arr, int n, int x){
    int low  = 0, high = n-1;
    int ans = n;
    while(low <= high){
    int mid = low + (high - low) / 2;
    
    if(arr[mid] >=  x){ 
        ans = mid;
        high = mid -1; //find elements >= x
        } else {
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
int checkNthPower(int mid, int n, int m){
    long long ans = 1;
    long long base = mid;
    long long power = n;
    for(int i = 0; i < n; i++){
        ans = ans*mid;
        if(ans > m) return 2;
        if(power % 2 == 1){        
            ans *= base;
            if(ans > m) return 2;
        }
        power /= 2;
        if(power > 0){
            base *= base;
            if(base > m) base = m + 1; // Prevent overflow
        }
    }
    if(ans == m) return 1;
    return (ans > m) ? 2 : 0;
}
int nthRoot(int n, int m){
    int low = 1, high  = m;
    while(low <= high){
        int mid = (low + high)/2;
        int midN = checkNthPower(mid, n , m);
        if(midN == 1){ return mid; }
        else if(midN == 0) low = mid+1;
        else high = mid - 1;
    }
    return -1;
}

//minm. no. of days for making m bouquets 
//i/p: array bloomday, m, k -> bloomday[i] => day when ith flower booms
//k => no. of adjacent flowers for making 1 out of the m bouquets
//return minm. no. of days to make m bouquets, each bouquet - plucking k flowers adjacent to each other
//brute force = start day 1 to max(bloomday) -> check no. of bouqets made = no. of k adjacent flower sets
//when no. of bouquets made that day >= m , return day
//T.C = O((max(bloomday)-min(bloomday)+1)*n)
int mindays(vector<int>& bloomDay, int m, int k){
    int n = bloomDay.size();
    if(1LL * m * k > n) return -1;

    int lastday = *max_element(bloomDay.begin(), bloomDay.end());

     for(int day = 1; day <= lastday; day++){
        int cnt = 0, bouqcnt = 0;
        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= day){
                cnt++;
                if(cnt == k){
                    bouqcnt++;
                    cnt = 0; 
                } 
            }    else {
                    cnt = 0;
                }
            }
        if(bouqcnt >= m) return day;   
    }     
    return -1;
}

//optimal solution = binary search
//same logic but instead of linear traversal of days use mid
//T.C = O( n * log(max(bloomday)-min(bloomday)+1) )
bool canMake(vector<int>& bloomDay, int m, int k, int day){
    int n = bloomDay.size();
    int cnt = 0, bouqcnt = 0;

    for(int i = 0; i < n; i++){
        if(bloomDay[i] <= day){
            cnt++;
        } else {
            bouqcnt += (cnt/k);
            cnt = 0;
        }
    }
    bouqcnt += (cnt/k);
    return (bouqcnt >= m);
}
int mindays(vector<int>& bloomDay, int m, int k){
    int n = bloomDay.size();
    if(1LL * m * k > n) return -1;

    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int low = *min_element(bloomDay.begin(), bloomDay.end());

    while(low <= high){
        int mid = low + (high-low)/2;

        if(canMake(bloomDay, m, k, mid)){
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return low;
}


//median of 2 sorted arrays
//brute force = use 3rd array to merge and then find median
//better approach: cnt and two pointers 
//O(n1+n2)
double Median(vector<int>& a, vector<int>& b){
    int n1 = a.size(), n2 = b.size();
    int i = 0, j = 0, n = n1+n2;
    int cnt = 0;
    int ind2 = n/2;
    int ind1 = ind2 - 1; 
    int ele1 = -1, ele2 = -1;

    while(i < n1 && j < n2){
        if(a[i] > b[j]){
            if(cnt == ind1) ele1 = b[j];
            if(cnt == ind2) ele2 = b[j];
            cnt++;
            j++;
        } else {
            if(cnt == ind1) ele1 = a[i];
            if(cnt == ind2) ele2 = a[i];
            cnt++;
            i++;
        }
    }

    while(i < n1){
        if(cnt == ind1) ele1 = a[i];
        if(cnt == ind2) ele2 = a[i];
        cnt++;
        i++;
    }

    while(j < n2){
        if (cnt == ind1) ele1 = b[j];
        if(cnt == ind2) ele2 = b[j];
        cnt++;
        j++;
    }
    if(n % 2 == 1) return ele2;
    return (double)((double)(ele1 + ele2))/2.0;
}

//optimal solution: binary search 
//T.C = O(log(min(m,n)))
double median(vector<int>& a, vector<int>& b){
    int m = a.size(), n = b.size();
    if(m > n) return median(b, a);

    //m < n
    int N = m + n;
    int left = (m + n + 1)/2; // length of left half 

    int low = 0; // from b need atleast 0 ele if k > m
    int high = m; // from a need m eles or lesser

    while(low <= high){
        int mid1 = (low+high)/2; // boundary of first half
        int mid2 = left - mid1; // boundary of second half & makes left half k eles long
        int l1, l2, r1, r2;

        l1 = (mid1 == 0 ? INT_MAX : a[mid1-1]);
        r1 = (mid1 == m ? INT_MIN : a[mid1]);
        
        l2 = (mid2 == 0 ? INT_MAX : b[mid2-1]);
        r2 = (mid2 == n? INT_MIN : b[mid2]);

        if(l1 <= r2 && l2 <= r1) {
            if(n % 2 == 1) return max(l1, l2);
            return (double)((max(l1, l2) + min(r1, r2)))/2.0;
        }
        if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}


//kth element in 2 sorted arrays when merged
//brute force = use 3rd array to merge and traverse and find the kth ele

//better approach - merge sort and two pointers related 
//T.C = O(m+n)
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

//optimal soln - binary search
//TC = O(log(min(m , n)))
int KthEle(vector<int>& a, vector<int>& b, int k){
    int m = a.size(), n = b.size();
    if(m > n) return KthEle(b, a, k);

    //m < n
    int left = k; // length of left half 

    int low = max(0, k - m); // from b need atleast k-m ele if k > m
    int high = min(k , n); // from a need k eles or lesser

    while(low <= high){
        int mid1 = (low+high)/2; // boundary of first half
        int mid2 = left - mid1; // boundary of second half & makes left half k eles long
        int l1, l2, r1, r2;

        l1 = (mid1 == 0 ? INT_MAX : a[mid1-1]);
        r1 = (mid1 == m ? INT_MIN : a[mid1]);
        
        l2 = (mid2 == 0 ? INT_MAX : b[mid2-1]);
        r2 = (mid2 == n? INT_MIN : b[mid2]);

        if(l1 <= r2 && l2 <= r1) return max(l1, l2);

        if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}

// optimized - T.C = O(log k)
int kthElement(vector<int>& a, vector<int>&b, int k){
    int m = a.size(), n = b.size();
        int i = 0, j = 0;
        
        while (true) {
            if (i == m) return b[j + k - 1];
            if (j == n) return a[i + k - 1];
            if (k == 1) return min(a[i], b[j]);
            
            int mid = k / 2;
            int new_i = min(i + mid, m) - 1;
            int new_j = min(j + mid, n) - 1;
            
            if (a[new_i] <= b[new_j]) {
                k -= (new_i - i + 1);
                i = new_i + 1;
            } else {
                k -= (new_j - j + 1);
                j = new_j + 1;
            }
        }    
}

