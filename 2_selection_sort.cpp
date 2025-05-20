#include <bits/stdc++.h>
using namespace std;

void selectionSort(int n, int *a)
{
  int i, j, temp, minIndex;
  int swapCount = 0;
  
  for( i = 0 ; i < n ; i++ ){
    minIndex = i;
    for(j = i+1; j < n; j++){
    if (a[j] < a[minIndex])
     minIndex=j;
    }
     
     if(minIndex!=i){
       temp=a[i];
       a[i]=a[minIndex];
       a[minIndex]=temp;
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