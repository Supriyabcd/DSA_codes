#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution{
    public: 
/*  #1 using hashmap
    TC: O(n log n), SC: O(n)*/
    int minSwaps1(vector<int>& arr){
        int n = arr.size();
        //temp. array storing arr elements in sorted order
        vector<int> temp = arr;
        sort(arr.begin(), arr.end());

        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++){
            mpp[arr[i]] = i;
        }

        int swapCnt = 0;
        for(int i = 0; i < n; i++){
            if(temp[i] != arr[i]){
                int ind = mpp[arr[i]];
                swap(arr[i], arr[ind]);

                mpp[arr[i]] = i;
                mpp[arr[ind]] = ind;
                swapCnt++;
            }
        }
        return swapCnt;
    }

/* #2 cycle detection
    TC : O(n log n), SC : O(n)
    example : arr[] = [2 4 5 1 3]
    5, 3 = forms a cycle; 2, 4 , 1 = forms a cycle
*/
    int minSwaps2(vector<int>& arr){
        int n = arr.size();

        vector<pair<int, int>> arrPos(n);
        for(int i = 0; i < n; i++){
            arrPos[i] = {arr[i], i};
        }

        //sort to get the sorted position
        sort(arrPos.begin(), arrPos.end());

        int swaps = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){

            //either elements is visited or element in the right position
            if(visited[i] || arrPos[i].second == i) 
                continue;
            
            int j = i; 
            int cycleSize = 0;

            while(!visited[j]){
                visited[j] = true;
                j = arrPos[j].second;
                cycleSize++;
            }
                /* // Hashing elements with their original positions
        unordered_map<int, int> pos; // same as above but with vector<vector<int>>
        for (int i = 0; i < n; i++)
            pos[arr[i]] = i;

        sort(arr.begin(), arr.end());

        int swaps = 0;
        for (int i = 0; i < n; i++) {

            // Already a part of another cycle Or
            // in its correct position
            if (vis[i] || pos[arr[i]] == i)
                continue;

            int j = i, cycleSize = 0;
        
            // We make a cycle until it comes
            // back to first element again.
            while (!vis[j]) {
                vis[j] = true;

                // move to next element of the cycle
                j = pos[arr[j]];
                cycleSize++;
        }*/
            if(cycleSize > 1){
                swaps += cycleSize - 1;
            }
        }
        return swaps;
    }

};