#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
  
int partition(int*a ,int low, int high)
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
 
 void quick_sort(int*a, int low, int high)
 {
   if (low < high) {
        int pivotIndex = partition(a, low, high);

        quick_sort(a, low, pivotIndex - 1);
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