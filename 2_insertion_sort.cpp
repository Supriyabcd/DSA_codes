#include <bits/stdc++.h>
using namespace std;
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