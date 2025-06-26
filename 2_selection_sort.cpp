#include <bits/stdc++.h>
using namespace std;

// T.C: O(n^2) S.C: O(1)
// It iterates through the array, finding the minimum element in the unsorted portion and swapping
// it with the first unsorted element. The process is repeated until the array is sorted.
// The number of swaps is also counted and printed at the end. - lesser swaps than bubble sort
// Selection sort is not a stable sort, meaning that it may change the relative order of equal elements.
//  not the most efficient algorithm for large datasets, but it is simple and easy to implement. 
// Loop invariant: After each iteration, the first i elements are sorted, and the remaining n-i elements are unsorted.

void selectionSort(int n, int *a)
{
  int i, j, temp, minIndex;
  int swapCount = 0;
  
  for( i = 0 ; i < n ; i++ ){
    minIndex = i;
    for(j = i+1; j < n; j++){
    if (a[j] < a[minIndex])
     minIndex = j;
    }
     
     if(minIndex != i){
       temp = a[i];
       a[i] = a[minIndex];
       a[minIndex] = temp;
       swapCount++;
     } 
   }  
   
   printf("The elements of array after sorting: ");
   for(int i=0;i<n;i++){
   printf("%d ",a[i]);
   }
   printf("\n The number of swaps : %d",swapCount);
} 

int main() {

int n;
printf("Enter the size of array: ");
scanf("%d",&n);

int a[n];
printf("Enter the elements of the array: ");
for(int i = 0; i < n; i++){
scanf("%d", &a[i]);
}

selectionSort(n, a);

return 0;
}