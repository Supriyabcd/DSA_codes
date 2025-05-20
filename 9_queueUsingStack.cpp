#include<bits/stdc++.h>
using namespace std;

class QueueUsingStack{
    private:
        stack<int> stack1, stack2;

        //move elements from stack1 to stack2
        void TransferStack1toStack2(){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

    public:
        //Enqueue op.
        void Enqueue(int value){
            stack1.push(value);
            cout << value << " enqueued" << endl;
        }

        //Dequeue op.
        void Dequeue(){
            if(stack2.empty()){
                if(stack1.empty()){
                    throw out_of_range("Queue is empty");
                }
                TransferStack1toStack2();
            }
            int topValue = stack2.top();
            stack2.pop();
            cout << topValue << " dequeued " << endl;
        }

        //Check if queue is Empty
        bool isEmpty(){
            return stack1.empty() && stack2.empty();
        }
        // printing queue

        void display(){
            TransferStack1toStack2();
            if(stack2.empty()){
                cout << "Stack is empty. \n";
            }else{
                std::stack<int> tempStack = stack2;
                cout << "Stack elements: " <<endl;
                while(!(tempStack.empty())){
                    cout << tempStack.top() << " " ;
                    tempStack.pop();
                }
                cout << "\n" ;
            }  
        }


};

int main()
{
    QueueUsingStack queue;
    int choice, data;
    do{
    cout << "Menu:\n" ;
    cout << "1. Enqueue\n" ;
    cout << "2. Dequeue\n" ;
    cout << "3. Check whether empty or not\n";
    cout << "4. Print queue\n";
    cout << "0. Exit\n" ;
    cout << "Enter your choice : " ;
    cin >> choice;

    switch(choice)
        {
            case 1: cout << "Enter integer to be enqueued : " ;
                    cin >> data;
                    queue.Enqueue(data);
                    break;
            case 2: queue.Dequeue();
                break;
            case 3: queue.isEmpty() ? cout << "Empty\n" : cout << "Not Empty\n";
                break; 
            case 4:queue.display();
                break;
            case 0: cout << "Exiting...." << endl;
                    return 0;
                break;
            default: "Invalid choice. Please enter an integer" ;
                break;                
        }
    } while(choice != 0); 
    
    return 0;
}
