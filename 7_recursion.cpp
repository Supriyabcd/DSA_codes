#include<iostream>
#include<vector>
using namespace std;

//print 1 to N
//normal recursion

void f_cnt(int n, int i){
    if(i > n) return;
    cout << i << endl;
    f_cnt(n, i+1);
}

//backtracking
void fCnt(int n, int i){
    if(i < 1) return;
    fCnt(n, i-1);
    cout << i <<endl;
}

//reverse an array
//using two pointers
void reverse_f(int arr[], int l, int r){
    if(l >= r) return;
    swap(arr[l], arr[r]);
    reverse_f(arr, l+1, r-1);
}
//using one pointer/variable
void reverse_arr(vector<int>arr, int i){
    int n = arr.size();
    if(i >= n/2) return;
    swap(arr[i], arr[n-i-1]);
    reverse_arr(arr, i+1);
}

//atoi()


//pow(x,n)
//idea = 2^10 = 4^5 = 4 * 4^4 = 4(nn-1 part)* 256(=x*x part)
double power(double x, int n){
    double ans = 1.0;
    long long nn = n;
    if(nn < 0) nn = -1*nn;
    while(nn > 0){
        if( nn % 2 == 1){
        ans = ans * x;
        nn = nn - 1;
        } else {
            x = x * x;
            nn = nn/2;
        } 
        if ( n < 0 ) ans = double (1.0)/ double (ans);
        return ans;
    }
}


int main(){
    f_cnt(4, 1);
    fCnt(5,5);
    return 0;
}