#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
        stack<int> stack;

    public:
        void Push(int data){
            stack.push(data);
            cout << data << " pushed to the stack\n";
        }

        void Pop(){
            if(stack.empty()){
                cout << "Stack is empty. Cannot pop\n";
            } else {
                int topvalue = stack.top();
                stack.pop();
                cout << topvalue << " popped from the stack\n"; 
            }
        }

        void Top(){
            if(stack.empty()){
                cout << "Stack is empty. No top element \n";
            } else {
                cout << "Top element is:" << stack.top() << endl;
            }
        }

        void printStack(){
            if(stack.empty()){
                cout << "Stack is empty. \n";
            }else{
                std::stack<int> tempStack = stack;
                cout << "Stack elements: " <<endl;
                while(!(tempStack.empty())){
                    cout << tempStack.top() << " " ;
                    tempStack.pop();
                }
                cout << "\n" ;
            }    
        }

        //check for balanced brackets
        bool isValid(string s) {
        vector<char> st; 
        for(auto it: s) {
            if(it=='(' || it=='{' || it == '[') st.push_back(it); 
            else {
                if(st.size() == 0) return false; 
                char ch = st.back(); 
                st.pop_back(); 
                if((it == ')' and ch == '(') or  (it == ']' and ch == '[') or (it == '}' and ch == '{')) continue;
                else return false;
            }
        }
        return st.empty(); 
        }

        /*The next greater element of some element x in an array is the first greater element 
        that is to the right of x in the same array.
        You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
        For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element 
        of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1. 
        Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.*/
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
        {
            unordered_map<int, int> ngeMap;  // Map to store next greater elements
            //stack<int> stack;                  // Stack for monotonic decreasing order
            
            // Traverse nums2 in reverse order to find next greater elements
            for (int i = nums2.size() - 1; i >= 0; i--) {
                while (!stack.empty() && stack.top() <= nums2[i]) {
                    stack.pop();
                }
                // If stack is empty, there's no greater element
                ngeMap[nums2[i]] = stack.empty() ? -1 : stack.top();
                stack.push(nums2[i]);
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
        which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number */
        vector<int> nextGreaterElements(vector<int>& nums) {
            int n = nums.size();
            vector<int> nge(n, -1);
            //stack<int> st;
            
            for(int i = 2*n - 1; i >= 0; i--){
                while(!stack.empty() && stack.top() <= nums[i%n]){
                    stack.pop();
                }
                if(i < n){
                    nge[i] = stack.empty() ? -1: stack.top();
                }
                stack.push(nums[i%n]);
            }
            return nge;
        }
};

int main()
{
    Stack S;
    int choice, data;

    do
    {
    cout << "Menu:" <<endl;
    cout << "1. Push \n" ;
    cout << "2. Pop \n" ;
    cout << "3. Top \n" ; 
    cout << "4. Print Stack \n";
    cout << "0. Exit \n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice){
            case 1: { cout << "Enter the element to be pushed: " ;
                    cin >> data;
                    S.Push(data); 
                break; }
            case 2: S.Pop();
                    break;
            case 3: S.Top();
                break;
            case 4: S.printStack();
                break;
            case 0: cout << "Exiting..." << endl;
                break;
            default: cout << "Invalid choice. Please enter a valid integer";
                break;
        }
    } while( choice != 0);

    return 0;
}
