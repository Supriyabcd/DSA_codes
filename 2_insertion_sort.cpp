#include <bits/stdc++.h>
using namespace std;

//inserting the element at the correct position
//T.C = O(n^2), S.C = O(1)
//stable sort - does not change the relative order of elements with equal keys
//in-place sort - sorts the array without requiring additional space for another array
//best case - O(n) when array is already sorted
//worst case - O(n^2) when array is reverse sorted

//after each ith pass, the ith element is inserted at its correct position in the sorted subarray
//loop invariant - at any point: the first i elements are sorted and the rest n-i elements are unsorted
//the number of passes is n-1, where n is the number of elements

void insertion_sort(int a[], int n){
int i,j;
  
  for(i = 1; i < n; i++){
     int key = a[i];
     j = i - 1;
     while(j >= 0 && a[j] > key){
       a[j+1] = a[j];
       j--;
    }
    a[j + 1] = key;
 }
  printf("The elements of the sorted array are:");
  for(int i = 0; i < n; i++)
  printf("%d ",a[i]);
  printf("\n");
}

int main()
{
  int n;
  printf("Enter the size of the array:");
  scanf("%d",&n);
  
  int a[n];
  printf("Enter the elements of the array:\n");
  for(int i = 0; i < n; i++){
  scanf("%d",&a[i]);
  }
  
  insertion_sort(a, n);
  
  return 0;
}