#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
 
//count frequency of element in arr
//using two loops - T : O(n*n)
void countFreq(int arr[], int n)
{
    vector<bool> visited(n, false);
 
    for (int i = 0; i < n; i++) {
 
        // Skip this element if already processed
        if (visited[i] == true)
            continue;
 
        // Count frequency
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << " " << count << endl;
    }
}
 
//using map - T: O(n) 
void Frequency(int arr[], int n)
{
    unordered_map<int, int> map;
 
    for (int i = 0; i < n; i++)
        map[arr[i]]++;
 
    // Traverse through map and print frequencies
    for (auto x : map)
        cout << x.first << " " << x.second << endl;
}
 
//finding highest/lowest frequency 
//brute force -using 2 loops
void maxfreq(int arr[], int n){

    vector<bool> visited(n, false);
    int maxFreq = 0, minFreq = 0;
    int maxEle = 0, minEle = 0;

    for(int i = 0; i < n; i++){

        if (visited[i] == true) continue;

        int count = 1;
        for(int j = 0; j < n; j++){
            if(arr[i] == arr[j]){
                count++;
                visited[i] = true;
            }
        }

        if(count > maxFreq)
        {
            maxEle = arr[i];
            maxFreq = count;
        }

        if(count < minFreq){
            minFreq = count;
            minEle = arr[i];
        }
    }

    cout << "The frequency of " << maxEle << "is " << maxFreq << " i.e. highest frequency" << endl;
    cout << "The frequency of " << minEle << "is " << minFreq << " i.e lowest frequency" << endl;
}

//optimal solution
void max_freq(int arr[], int n){

    unordered_map <int,int> mpp;

    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }

    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;

    for (auto it : mpp) {
        int count = it.second;
        int element = it.first;

        if (count > maxFreq) {
            maxEle = element;
            maxFreq = count;
        }
        if (count < minFreq) {
            minEle = element;
            minFreq = count;
        }
    }

    cout << "The highest frequency element is: " << maxEle << "\n";
    cout << "The lowest frequency element is: " << minEle << "\n";
}

int main()
{
    int arr[] = {10,5,10,15,10,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Frequency(arr, n);
    max_freq(arr, n);
    return 0;
}


