// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


int main() {
    int  t,n;
    cin >> t;
    
    while(t--){
        cin >> n;
        vector<char> S(4*n);
        for(int i = 0; i < 4*n ; i++){
            cin >> S[i];
        }
        unordered_map <char,int> mpp;
        int questionMarks = 0;
        for(char c : S){
            if(c == '?'){
                questionMarks++;
            } else {
                mpp[c]++;
            }   
        }   
        int maxScore = 0;

        for (char option : {'A', 'B', 'C', 'D'}) {
            int correctCount = min(mpp[option], n);
            maxScore += correctCount;
            int needed = n - correctCount;
                int fill = min(needed, questionMarks);
                maxScore += fill;
                questionMarks -= fill;
        }
        cout << maxScore << endl;
    }    
    return 0;
    
}