//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        double totVal = 0.0; 
        int n = val.size();
        vector<pair<double, pair<int, int>>> items;

        for(int i = 0 ; i < n; i++){
            double perW = (double)val[i] / wt[i];
            items.push_back({perW, {val[i], wt[i]}});
        }
        sort(items.rbegin(), items.rend());
        for (auto& item : items) {
            int value = item.second.first;
            int weight = item.second.second;

            if (capacity >= weight) {
                // Take the whole item
                totVal += value;
                capacity -= weight;
            } else {
                // Take fractional part of the item
                totVal += item.first * capacity; // item.first is value/weight
                break; // Knapsack is full
            }
        }
        return totVal;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends