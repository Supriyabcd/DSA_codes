#include<bits\stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    } 
}

void buildMaxHeap(vector<int>& arr){
    int n = arr.size();
    for (int i = n/2-1 ; i >= 0; i--){
        heapify(arr, n, i);
    }
}

void printHeap(const vector<int>& arr){
    for(int val : arr)
        cout << val << " ";
    cout << endl;
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    buildMaxHeap(arr);

    cout << "Max Heap: \n";
    printHeap(arr);

    return 0;
}