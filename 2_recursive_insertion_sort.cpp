#include <bits/stdc++.h>
using namespace std;
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