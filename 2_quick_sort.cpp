#include<bits/stdc++.h>
using namespace std;

//divide and conquer algorithm
//partitioning the array into two parts based on the pivot element
//elements less than the pivot go to the left, and elements greater than the pivot go to the right
//then recursively applying the same logic to the left and right parts

//Time Complexity: O(n log n) on average, O(n^2) in the worst case
//Space Complexity: O(log n) for the recursive stack space
//Stable Sort: No, it does not maintain the relative order of equal elements
//In-Place Sort: Yes, it sorts the array without requiring additional space for another array

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//this function takes the last element as pivot 
//places the pivot element at its correct position in sorted array 
//places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot
//it returns the index of the pivot element after partitioning
int partition(int* a, int low, int high)
{
   int pivot = a[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (a[j] < pivot) 
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);
    return (i + 1);
}
 
 void quick_sort(int* a, int low, int high)
 {
   if (low < high) {
        int pivotIndex = partition(a, low, high);

        quick_sort(a, low, pivotIndex - 1); 
        //note that we are not including the pivot element in the left part
        //so we are passing pivotIndex - 1 as the high index for the left part
        quick_sort(a, pivotIndex + 1, high);
    }
 }

 int main() {

    int arr[7] = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    quick_sort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0 ;
}