#include<bits/stdc++.h>
using namespace std;

class stackUsingQueue{
    private: 
        queue<int> queue;
        
    public:
        void Push(int value) {
            int size = queue.size();
            queue.push(value);
            //Move all prev elements to the back of queue
            for(int i = 0; i < size; i++){
                queue.push(queue.front());
                queue.pop();
            }
            cout << value << " pushed into stack." << endl;
        }

        void Pop(){
            if(queue.empty()){
                throw out_of_range("Stack is empty");
            }
            int topValue = queue.front();
            queue.pop();
            cout << topValue << " popped from stack." << endl;
        }

        void Top(){
            if (queue.empty()){
                cout << "Stack is empty. No top element" << endl;
            }
            int TopValue = queue.front();
            cout << TopValue << " is top element" << endl;
        }
        
        void display(){
            if(queue.empty()){
                cout << "Queue is empty. \n ";
            } else {
                std::queue<int> tempQueue = queue;
                cout << "Queue elements: ";
                while(!tempQueue.empty()){
                    cout << tempQueue.front() << " ";
                    tempQueue.pop();
                }
                cout << "\n";
            }
        }    
};

int main(){
    stackUsingQueue stack;
    int choice, data;

    do
    {
    cout << "Menu:" <<endl;
    cout << "1. Push \n" ;
    cout << "2. Pop \n" ;
    cout << "3. Top \n" ; 
    cout << "4. Display\n";
    cout << "0. Exit \n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice){
            case 1: { 
                    cout << "Enter the element to be pushed: " ;
                    cin >> data;
                    stack.Push(data); 
                break; }
            case 2: stack.Pop();
                    break;
            case 3: stack.Top();
                break;
            case 4: stack.display();
                break;
            case 0: cout << "Exiting..." << endl;
                break;
            default: cout << "Invalid choice. Please try again " << endl;
                break;
        }
    } while( choice != 0);

    return 0;
}
