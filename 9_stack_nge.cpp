#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and 
determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
    */
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ngeMap;  // Map to store next greater elements
        stack<int> st;                  // Stack for monotonic decreasing order
        
        // Traverse nums2 in reverse order to find next greater elements
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            // If stack is empty, there's no greater element
            ngeMap[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        // Prepare result for nums1
        vector<int> nge;
        for (int num : nums1) {
            nge.push_back(ngeMap[num]);
        }

        return nge;
    }

/*Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array, 
which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
*/
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;
        
        for(int i = 2*n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            if(i < n){
                nge[i] = st.empty() ? -1: st.top();
            }
            st.push(nums[i%n]);
        }
        return nge;
    }
};