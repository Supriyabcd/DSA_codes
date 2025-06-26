#include <bits/stdc++.h>
using namespace std;

//same logic as insertion sort but using recursion
//but outer i loop gone
//main() calls recursive_insertion_sort with i = 1, next calls itself with i+1 until i becomes n
//The function takes an array and its size as input and sorts the array in place.

//Time complexity: O(n^2)
//Space complexity: O(n) due to recursion stack
//Stable sort: Yes

void recursive_insertion_sort(int a[], int n, int i){
     
    if (i>= n) return;
    int key = a[i];
    int j = i - 1;
    while(j >= 0 && a[j] > key){
       a[j+1] = a[j];
       j--;
    }
    a[j + 1] = key;
   
  recursive_insertion_sort(a, n, i + 1);
}

int main()
{
  int n;
  printf("Enter the size of the array: ");
  scanf("%d",&n);
  
  int a[n];
  printf("Enter the elements of the array:\n");
  for(int i = 0; i < n; i++){
  scanf("%d",&a[i]);
  }
  
  recursive_insertion_sort(a, n, 1);
  
  printf("The elements of the sorted array are: ");
  for(int i = 0; i < n; i++)
  printf("%d ",a[i]);
  printf("\n");
  return 0;
}