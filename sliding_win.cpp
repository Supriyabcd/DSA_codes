#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, sum = 0;
        int minlen = INT_MAX;
        for(int r = 0;r < nums.size(); r++){
            sum += nums[r];
            if(sum >= target){
                if( r-l+1 < minlen){
                    minlen = r-l+1;
                }
                sum -= nums[l];
                l++; 
            }
        }
        return (minlen == INT_MAX)? 0 : minlen;
    }
};

int main(){
    Solution S;
    vector<int> arr= {2,3,1,2,4,3};
    int target = 7;
    cout << S.minSubArrayLen(7, arr) << endl;
    return 0;
}