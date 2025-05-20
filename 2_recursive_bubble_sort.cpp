#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void recursive_bubble_sort(int a[], int n){
    
    if (n == 1) return;

    int swapCount = 0;
    bool swapped = false;  
 
        for(int j = 0; j <= n-2; j++){
            if (a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
                swapped = true;
                swapCount++;
            }
        }
        if (swapped == false)
            return;
    
    recursive_bubble_sort(a, n-1);
    
    swapped ? printf("Swap Count = %d\n ", swapCount) : printf("No swapping occured\n");
        
}

int main(){
    int n;
    cout << "Enter array size: " ;
    cin >> n;

    int a[n];
    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    recursive_bubble_sort(a, n);

    cout << "Elements of sorted array:\n";
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}