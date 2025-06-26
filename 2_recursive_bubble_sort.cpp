#include <bits/stdc++.h>
using namespace std;

//same as bubble sort, but implemented recursively - loop i removed 
//main() calls recursive_bubble_sort() with n as the size of the array
//next calls itself with n-1 until n becomes 1
//T.C = O(n^2), S.C = O(1)

//stable sort - does not change the relative order of elements with equal keys
//in-place sort - sorts the array without requiring additional space for another array
//best case - O(n) when array is already sorted
//worst case - O(n^2) when array is reverse sorted

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
    
    // After one pass, the largest element is at the end
    // Recursively call for the remaining array n-1 elements
    // The last element is already in its correct position
    
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