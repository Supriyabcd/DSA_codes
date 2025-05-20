#include<bits/stdc++.h>
using namespace std;

class Queue{
    private:
        queue<int> queue;

    public:
        void enqueue(int data){
            queue.push(data);
            cout << data << " enqueued to the queue. \n";
        }

        void dequeue(){
            if(queue.empty()){
                cout <<"Queue is empty. Cannot dequeue\n";
                } else {
                    int frontValue = queue.front();
                    queue.pop();
                    cout << frontValue << " dequeued from the queue\n";  
                }

        }

        void PeekFront(){
            if(queue.empty()){
                cout << "Queue is empty. No front element.\n" ;
            } else {
                cout << " Front element is : " << queue.front() << endl;
            }
        }

        void printQueue(){
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

int main()
{
    Queue Q;
    int choice, data;
    do{
    cout << "Menu:\n" ;
    cout << "1. Enqueue\n" ;
    cout << "2. Dequeue\n" ;
    cout << "3. PeekFront\n";
    cout << "4. Print Queue\n" ;
    cout << "0. Exit\n" ;
    cout << "Enter your choice :" ;
    cin >> choice;

    switch(choice)
        {
            case 1: cout << "Enter integer to be enqueued :" ;
                    cin >> data;
                    Q.enqueue(data);
                    break;
            case 2: Q.dequeue();
                break;
            case 3: Q.PeekFront();
                break;
            case 4: Q.printQueue();
                break;    
            case 0: cout << "Exiting...." << endl;
                    return 0;
                break;
            default: "Invalid choice. Please enter an integer" ;
                break;                
        }
    }while(choice != 0);   
    return 0;
}