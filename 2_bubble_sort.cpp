#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(vector<int>& a, int n){
     
    int swapCount = 0;
    bool swapped;  

    for(int i = 0; i < n-1; i++){
        swapped = false;
        for(int j = 0; j < n-i-1; j++){
            if (a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
                swapped = true;
                swapCount++;
            }
        }
        if (swapped == false)
            break;
    }
    
    swapped ? printf("Swap Count = %d\n ", swapCount) : printf("No swapping occured\n");
    printf("Elements of sorted array:\n ");
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main(){
    int n;
    cout << "Enter array size: " ;
    cin >> n;

    vector<int> a(n);
    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    bubble_sort(a, n);

    return 0;
}